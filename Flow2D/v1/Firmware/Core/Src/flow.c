#include "generic.h"
#include "qfplib.h"
#include "config.h"
#include "complex.h"
#include "interpolate.h"
#include "flow.h"
#include "temperature.h"
#include "correlation.h"

/* Imported variables ------------------------------------------------------*/
extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;

/* Private variables -------------------------------------------------------*/
// ISR variables.
static uint16_t ADCBuffer[2 * FLOW_ADC_CHANNELS * ADC_NUM_OF_SAMPLES];
static volatile int32_t __SumX[FLOW_CHANNELS];
static volatile int32_t __SumY[FLOW_CHANNELS];
static volatile uint16_t __TrackPosition;
static volatile int32_t SumX[FLOW_CHANNELS];
static volatile int32_t SumY[FLOW_CHANNELS];
static volatile uint16_t TrackPosition;
static uint16_t DownsamplingNumber;
static volatile int32_t DownsamplingCounter;
static uint16_t Locked;

// Searching variables.
static Complex_t SearchingVector[SEARCHING_SAMPLE_POINTS];
static uint16_t SearchingDatapoint;

// Run variables.
static float RunVxFilterOut;
static float RunVyFilterOut;
static float RunVelocityFilterCoeff;
static float Search2CalibrationVectorTranslation;
static float MaxTemp = 0.0;

// Calibration variables.
static Flow_Calibration_t *Calibration;
float CalibrationPhasorX[FLOW_CHANNELS][CALIBRATION_SAMPLE_POINTS];
float CalibrationPhasorY[FLOW_CHANNELS][CALIBRATION_SAMPLE_POINTS];
static uint16_t CalibrationDatapoint;

// Flow control & common.
static Flow_Status_t Status = FLOW_STATUS_READY;
static uint16_t Skip;
static volatile Bool_t MeasurementCompleted;
static volatile Bool_t Tracking;

// Callbacks.
static Flow_CalibrationCompletedCallback_t CalibrationCompletedCb = NULL;
static Flow_MeasurementCompletedCallback_t MeasurementCompletedCb = NULL;
static Flow_SearchCompletedCallback_t SearchCompletedCb = NULL;

/* Private function prototypes----------------------------------------------*/
static void initializeISRVariables(uint16_t downsamplingNumber, uint16_t runTrackIdx);
static void startEngine(void);
static void stopEngine(void);
static float getWavelength(float equivalentCalibrationVectorPosition, float calibrationSpeedOfSound);
static void process(uint16_t *buff);
static void updatePeriod(uint16_t tim1_period);
static void getChannelPhasors(volatile int32_t *sumX, volatile int32_t *sumY, Complex_t *phasors);
static void convertPhasorsToPhasorDivisions(Complex_t *phasors, Complex_t *divisions);
static void triplePhasorMultiply(Complex_t *phasors, Complex_t *result);

/* Exported functions ------------------------------------------------------*/
Bool_t Flow_Calibrate(Flow_Calibration_t *calibrationResult, float speedOfSound,
                      Flow_CalibrationCompletedCallback_t calibrationCompletedCb)
{
    if (Status != FLOW_STATUS_READY)
    {
        return FALSE;
    }

    // Set callback function.
    CalibrationCompletedCb = calibrationCompletedCb;

    // Set calibration struct pointer.
    Calibration = calibrationResult;
    Calibration->speedOfSound = speedOfSound;

    // Initialize calibration process variables.
    CalibrationDatapoint = 0;

    // Initialize flow control variables.
    Skip = FLOW_CALIBRATION_SKIP;
    Tracking = FALSE;
    MeasurementCompleted = 0;

    // Initialize ISR variables.
    initializeISRVariables(FLOW_CALIBRATION_DOWNSAMPLING_NUMBER, 0);

    // Set frequency.
    updatePeriod(CALIBRATION_PERIOD_START);

    // Start ADC and other peripherals.
    startEngine();

    // Set status to calibrating.
    Status = FLOW_STATUS_CALIBRATING;

    return TRUE;
}

Bool_t Flow_SearchSpeedOfSound(Flow_Calibration_t *calibration,
                               Flow_SearchCompletedCallback_t searchCompletedCb)
{
    if (Status != FLOW_STATUS_READY)
    {
        return FALSE;
    }

    // Set callback function.
    SearchCompletedCb = searchCompletedCb;

    // Set calibration struct pointer.
    Calibration = calibration;

    // Initialize calibration process variables.
    SearchingDatapoint = 0;

    // Initialize flow control variables.
    Skip = FLOW_SEARCHING_SKIP;
    Tracking = FALSE;
    MeasurementCompleted = 0;

    // Initialize ISR variables.
    initializeISRVariables(FLOW_SEARCHING_DOWNSAMPLING_NUMBER, 0);

    // Set frequency.
    updatePeriod(SEARCHING_PERIOD_START);

    // Start ADC and other peripherals.
    startEngine();

    // Set status to calibrating.
    Status = FLOW_STATUS_SEARCHING;

    return TRUE;
}

Bool_t Flow_Run(Flow_Calibration_t *calibration, float searchCalibrationOffset, Flow_RunParams_t *params,
                Flow_MeasurementCompletedCallback_t measurementCompletedCb)
{
    if (Status != FLOW_STATUS_READY)
    {
        return FALSE;
    }

    // Set callback and calibration struct.
    MeasurementCompletedCb = measurementCompletedCb;
    Calibration = calibration;

    float measurement_period;
    measurement_period = qfp_fdiv(qfp_int2float((int32_t)params->downsamplingNumber),
                                  (((float)ADC_RUN_TRIGGER_FREQ) / ADC_NUM_OF_SAMPLES));

    // Initialize run variables.
    RunVxFilterOut = 0.0f;
    RunVyFilterOut = 0.0f;
    RunVelocityFilterCoeff = qfp_fdiv(measurement_period,
                                      qfp_fadd(params->velocityFilterTc, measurement_period));
    Search2CalibrationVectorTranslation = searchCalibrationOffset;
    TrackPosition = RUN_TRACKING_START_IDX;

    // Initialize flow control variables.
    Skip = FLOW_RUN_SKIP;
    Tracking = TRUE;
    MeasurementCompleted = 0;

    // Initialize ISR variables.
    initializeISRVariables(params->downsamplingNumber, RUN_TRACKING_START_IDX);

    // Set frequency.
    updatePeriod(TIM1_RUN_PERIOD);

    // Start ADC and other peripherals.
    startEngine();

    // Set status to running.
    Status = FLOW_STATUS_RUNNING;

    return TRUE;
}

void Flow_Execute(void)
{
    if (MeasurementCompleted)
    {
        if (Skip != 0)
        {
            Skip--;
        }
        else if (Status == FLOW_STATUS_CALIBRATING)
        {
            Locked = TRUE;
            getChannelPhasors(SumX, SumY, Calibration->calibrationVector[CalibrationDatapoint]);
            Locked = FALSE;

            // Increase datapoint counter.
            CalibrationDatapoint++;
            if (CalibrationDatapoint < CALIBRATION_SAMPLE_POINTS)
            {
                // Update frequency.
                stopEngine();
                updatePeriod(CALIBRATION_PERIOD_START + CALIBRATION_PERIOD_STEP * CalibrationDatapoint);
                initializeISRVariables(DownsamplingNumber, 0);
                startEngine();

                // Update skip counter.
                Skip = FLOW_CALIBRATION_SKIP;
            }
            else
            {
                stopEngine();

                // Set status to ready.
                Status = FLOW_STATUS_READY;

                // Return calibration vector.
                CalibrationCompletedCb(Calibration);
            }
        }
        else if (Status == FLOW_STATUS_SEARCHING)
        {
            Complex_t channel_phasors[FLOW_CHANNELS];

            // Calculate the difference in phase of the input signal.
            Locked = TRUE;
            getChannelPhasors(SumX, SumY, channel_phasors);
            Locked = FALSE;

            triplePhasorMultiply(channel_phasors, &SearchingVector[SearchingDatapoint]);

            // Increase datapoint counter.
            SearchingDatapoint++;
            if (SearchingDatapoint < SEARCHING_SAMPLE_POINTS)
            {
                // Update frequency.
                stopEngine();
                updatePeriod(SEARCHING_PERIOD_START + SEARCHING_PERIOD_STEP * SearchingDatapoint);
                initializeISRVariables(DownsamplingNumber, 0);
                startEngine();

                // Update skip counter.
                Skip = FLOW_SEARCHING_SKIP;
            }
            else
            {
                stopEngine();

                Complex_t y1[CALIBRATION_SAMPLE_POINTS];
                Complex_t *y2 = SearchingVector;

                // Get multiplication phasor which is related to wavenumber.
                for (uint16_t i = 0; i < CALIBRATION_SAMPLE_POINTS; i++)
                {
                    triplePhasorMultiply(Calibration->calibrationVector[i], &y1[i]);
                }

                float best_score = -1.0f;
                float best_position = 0.0f;

                // Match the search vector to calibration vector.
                for (uint32_t i = 0; i < ((CALIBRATION_SAMPLE_POINTS - SEARCHING_SAMPLE_POINTS) - 2); i++)
                {
                    float score;
                    for (uint32_t j = 0; j < CORRELATION_INTERPOLATION_NUMBER; j++)
                    {
                        score = Correlation_GetScore(y1, y2, i, SEARCHING_SAMPLE_POINTS,
                                                     qfp_fdiv(qfp_uint2float(j), ((float)CORRELATION_INTERPOLATION_NUMBER)));

                        if (score > best_score)
                        {
                            best_score = score;
                            best_position = qfp_fadd(qfp_uint2float(i),
                                                     qfp_fdiv(qfp_uint2float(j), ((float)CORRELATION_INTERPOLATION_NUMBER)));
                        }
                    }
                }

                Status = FLOW_STATUS_READY;

                // Obtain speed of sound.
                float speed_of_sound;
                float temperature;
                speed_of_sound = qfp_fdiv(getWavelength((qfp_fadd(best_position, (float)RUN_TRACKING_START_IDX)), Calibration->speedOfSound),
                                          ((float)TIM1_RUN_PERIOD / (float)TIM1_CLOCK_FREQ));

                temperature = Temperature_GetTemperature(speed_of_sound);

                SearchCompletedCb(best_position, best_score, temperature);
            }
        }
        else if (Status == FLOW_STATUS_RUNNING)
        {
            Complex_t phasors[FLOW_CHANNELS];
            float ftrack_position_on_calvec;
            uint16_t __track_position;
            int32_t __sum_x[FLOW_CHANNELS];
            int32_t __sum_y[FLOW_CHANNELS];

            // Volatile variables to be copied.
            Locked = TRUE;
            __track_position = TrackPosition;
            __sum_x[0] = SumX[0];
            __sum_x[1] = SumX[1];
            __sum_x[2] = SumX[2];
            __sum_y[0] = SumY[0];
            __sum_y[1] = SumY[1];
            __sum_y[2] = SumY[2];
            Locked = FALSE;

            // Get phasor channels.
            getChannelPhasors(__sum_x, __sum_y, phasors);

            // Calculate track position with respect to calibration vector.
            {
                Complex_t phasor_multiplication;

                // Obtain multiplication of three phasors.
                triplePhasorMultiply(phasors, &phasor_multiplication);

                // Calculate the interpolated float track_idx. Update the integer track idx if needed.
                Complex_t phasor_div;
                float x_interval;
                float relative_x;
                float relative_y;

                Complex_DivideWithoutNormalizing(&SearchingVector[__track_position + 1],
                                                 &SearchingVector[__track_position - 1],
                                                 &phasor_div);

                x_interval = Complex_FastArgument(&phasor_div);
                Complex_DivideWithoutNormalizing(&phasor_multiplication,
                                                 &SearchingVector[__track_position - 1],
                                                 &phasor_div);

                // Consider searching vector track position change as a function of relative phase and by using phase difference
                //and relative phase, calculate position change.
                relative_x = Complex_FastArgument(&phasor_div);
                relative_y = Interpolate_FirstOrderInterpolate(x_interval, 2.0f, relative_x);

                // There are two phasor vectors. One of them is the search vector; and the other one is the calibration vector.
                // The idea is to shift the search vector such that these two vectors are equal on some window.
                ftrack_position_on_calvec = qfp_fadd(Search2CalibrationVectorTranslation,
                                                     qfp_fadd(relative_y, qfp_uint2float((uint32_t)__track_position - 1)));
            }

            // Interpolate to find out offsets.
            Complex_t calibration_offsets[FLOW_CHANNELS];
            {
                Complex_t phasor_divs1[FLOW_CHANNELS];
                Complex_t phasor_divs2[FLOW_CHANNELS];
                Complex_t phasor_divs3[FLOW_CHANNELS];
                uint16_t calvec_track_idx;
                float relative_x;

                calvec_track_idx = (uint16_t)qfp_float2uint(qfp_fadd(ftrack_position_on_calvec, 0.5f));

                // Convert phasors to differential form since they can be interpolated better.
                convertPhasorsToPhasorDivisions(Calibration->calibrationVector[calvec_track_idx - 1], phasor_divs1);
                convertPhasorsToPhasorDivisions(Calibration->calibrationVector[calvec_track_idx], phasor_divs2);
                convertPhasorsToPhasorDivisions(Calibration->calibrationVector[calvec_track_idx + 1], phasor_divs3);

                // Interpolate offset phasors.
                relative_x = qfp_fsub(ftrack_position_on_calvec, qfp_uint2float((uint16_t)calvec_track_idx - 1));

                for (uint16_t i = 0; i < FLOW_CHANNELS; i++)
                {
                    float xdiff[2] = {1.0f, 1.0f};
                    float ydiff_real[2];
                    float ydiff_img[2];

                    ydiff_real[0] = qfp_fsub(phasor_divs2[i].real, phasor_divs1[i].real);
                    ydiff_img[0] = qfp_fsub(phasor_divs2[i].img, phasor_divs1[i].img);
                    ydiff_real[1] = qfp_fsub(phasor_divs3[i].real, phasor_divs2[i].real);
                    ydiff_img[1] = qfp_fsub(phasor_divs3[i].img, phasor_divs2[i].img);

                    calibration_offsets[i].real = Interpolate_SecondOrderInterpolate(xdiff, ydiff_real, relative_x);
                    calibration_offsets[i].img = Interpolate_SecondOrderInterpolate(xdiff, ydiff_img, relative_x);

                    calibration_offsets[i].real = qfp_fadd(calibration_offsets[i].real, phasor_divs1[i].real);
                    calibration_offsets[i].img = qfp_fadd(calibration_offsets[i].img, phasor_divs1[i].img);
                }
            }

            // Obtain temperature and wind velocity.
            float speed_of_sound;
            float vx, vy;
            {
                float phasediff[FLOW_CHANNELS];

                convertPhasorsToPhasorDivisions(phasors, phasors);

                speed_of_sound = qfp_fdiv(getWavelength(ftrack_position_on_calvec, Calibration->speedOfSound),
                                          ((float)TIM1_RUN_PERIOD / (float)TIM1_CLOCK_FREQ));

                for (uint16_t i = 0; i < FLOW_CHANNELS; i++)
                {
                    Complex_DivideWithoutNormalizing(&phasors[i], &calibration_offsets[i], &phasors[i]);
                    phasediff[i] = Complex_Argument(&phasors[i]);
                }

                float speed_of_sound2;
                speed_of_sound2 = qfp_fmul(speed_of_sound, speed_of_sound);

                vx = qfp_fmul(qfp_fmul(qfp_fsub(qfp_fadd(phasediff[2], phasediff[1]), phasediff[0]), speed_of_sound2),
                              (1.0f / (FLOW_RUN_GAIN * 2.0f * M_SQRT3)));
                vy = qfp_fmul(qfp_fmul(qfp_fsub(phasediff[2], phasediff[1]), speed_of_sound2),
                              (1.0f / (FLOW_RUN_GAIN * 3.0f)));
            }

            float temperature;

            // Filter velocity components and the temperature.
            RunVxFilterOut = qfp_fadd(qfp_fmul(vx, RunVelocityFilterCoeff),
                                      qfp_fmul(RunVxFilterOut, qfp_fsub(1.0f, RunVelocityFilterCoeff)));
            RunVyFilterOut = qfp_fadd(qfp_fmul(vy, RunVelocityFilterCoeff),
                                      qfp_fmul(RunVyFilterOut, qfp_fsub(1.0f, RunVelocityFilterCoeff)));

            temperature = Temperature_GetTemperature(speed_of_sound);
            if (temperature > MaxTemp)
            {
                MaxTemp = temperature;
            }

            MeasurementCompletedCb(RunVxFilterOut, RunVyFilterOut, temperature);
        }

        MeasurementCompleted--;
    }
}

void Flow_Stop(void)
{
    stopEngine();
    Status = FLOW_STATUS_READY;
}

/* Private functions -------------------------------------------------------*/
void startEngine(void)
{
    __HAL_TIM_SET_COUNTER(&htim1, 0);
    __HAL_TIM_SET_COUNTER(&htim3, 0);

    // Start ultrasonic transducer timer. This will also trigger the start of timer3.
    if (HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1) != HAL_OK)
    {
        while (1)
            ;
    }

    // Start ADC.
    if (HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADCBuffer, sizeof(ADCBuffer) / sizeof(ADCBuffer[0])))
    {
        while (1)
            ;
    }

    // Start ADC trigger channel.
    if (HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1) != HAL_OK)
    {
        while (1)
            ;
    }
}

void stopEngine(void)
{
    // Stop ultrasonic transducer timer
    if (HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1) != HAL_OK)
    {
        while (1)
            ;
    }

    // Stop ADC.
    if (HAL_ADC_Stop_DMA(&hadc1) != HAL_OK)
    {
        while (1)
            ;
    }

    // Stop ADC trigger channel.
    if (HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1) != HAL_OK)
    {
        while (1)
            ;
    }
}

float getWavelength(float equivalentCalibrationVectorPosition, float calibrationSpeedOfSound)
{
    float equivalent_period;
    equivalent_period = qfp_fdiv(qfp_fadd(qfp_fmul(equivalentCalibrationVectorPosition, ((float)CALIBRATION_PERIOD_STEP)),
                                          ((float)CALIBRATION_PERIOD_START)),
                                 ((float)TIM1_CLOCK_FREQ));

    return qfp_fmul(equivalent_period, calibrationSpeedOfSound);
}

void updatePeriod(uint16_t tim1_period)
{
    __HAL_TIM_SET_AUTORELOAD(&htim1, (tim1_period - 1));
    __HAL_TIM_SET_AUTORELOAD(&htim3, ((tim1_period >> 2) - 1));
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, (tim1_period >> 1));
}

void initializeISRVariables(uint16_t downsamplingNumber, uint16_t runTrackIdx)
{
    __SumX[0] = 0;
    __SumX[1] = 0;
    __SumX[2] = 0;
    __SumY[0] = 0;
    __SumY[1] = 0;
    __SumY[2] = 0;
    __TrackPosition = runTrackIdx;
    Locked = FALSE;
    DownsamplingCounter = 0;
    DownsamplingNumber = downsamplingNumber;
}

void getChannelPhasors(volatile int32_t *sumX, volatile int32_t *sumY, Complex_t *phasors)
{
    for (uint16_t i = 0; i < FLOW_CHANNELS; i++)
    {
        phasors[i].real = qfp_int2float(SumX[i]);
        phasors[i].img = qfp_int2float(SumY[i]);

        Complex_Normalize(&phasors[i], &phasors[i]);
    }
}

void convertPhasorsToPhasorDivisions(Complex_t *phasors, Complex_t *divisions)
{
    Complex_t division0;

    Complex_DivideWithoutNormalizing(&phasors[1], &phasors[0], &division0);
    Complex_DivideWithoutNormalizing(&phasors[2], &phasors[1], &divisions[1]);
    Complex_DivideWithoutNormalizing(&phasors[0], &phasors[2], &divisions[2]);

    divisions[0].real = division0.real;
    divisions[0].img = division0.img;
}

void triplePhasorMultiply(Complex_t *phasors, Complex_t *result)
{
    result->real = 1.0f;
    result->img = 0.0f;

    Complex_Multiply(result, &phasors[0], result);
    Complex_Multiply(result, &phasors[1], result);
    Complex_Multiply(result, &phasors[2], result);
}

void process(uint16_t *buff)
{
    for (uint16_t i = 0; i < ADC_NUM_OF_SAMPLES; i++)
    {
        if ((i & 0b11) == 0)
        {
            __SumX[0] += buff[FLOW_ADC_CHANNELS * i];
            __SumX[1] += buff[FLOW_ADC_CHANNELS * i + 1];
            __SumX[2] += buff[FLOW_ADC_CHANNELS * i + 2];
        }
        else if ((i & 0b11) == 1)
        {
            __SumY[0] += buff[FLOW_ADC_CHANNELS * i];
            __SumY[1] += buff[FLOW_ADC_CHANNELS * i + 1];
            __SumY[2] += buff[FLOW_ADC_CHANNELS * i + 2];
        }
        else if ((i & 0b11) == 2)
        {
            __SumX[0] -= buff[FLOW_ADC_CHANNELS * i];
            __SumX[1] -= buff[FLOW_ADC_CHANNELS * i + 1];
            __SumX[2] -= buff[FLOW_ADC_CHANNELS * i + 2];
        }
        else
        {
            __SumY[0] -= buff[FLOW_ADC_CHANNELS * i];
            __SumY[1] -= buff[FLOW_ADC_CHANNELS * i + 1];
            __SumY[2] -= buff[FLOW_ADC_CHANNELS * i + 2];
        }
    }

    // Return if locked. Results will be processed at the next ISR.
    if (Locked)
    {
        return;
    }

    // Run tracking algorithm.
    if (Tracking)
    {
        // Take multiplicand of all phases.
        Complex_t temp1, temp2, temp3, phasor_mult;
        temp1.real = qfp_int2float(__SumX[0]);
        temp1.img = qfp_int2float(__SumY[0]);
        temp2.real = qfp_int2float(__SumX[1]);
        temp2.img = qfp_int2float(__SumY[1]);
        temp3.real = qfp_int2float(__SumX[2]);
        temp3.img = qfp_int2float(__SumY[2]);

        Complex_Multiply(&temp1, &temp2, &phasor_mult);
        Complex_Multiply(&phasor_mult, &temp3, &phasor_mult);

        Complex_DivideWithoutNormalizing(&phasor_mult, &SearchingVector[__TrackPosition - 1], &temp1);
        Complex_DivideWithoutNormalizing(&SearchingVector[__TrackPosition + 1], &phasor_mult, &temp2);

        if (temp1.img > 0.0f)
        {
            __TrackPosition--;
        }
        else if (temp2.img > 0.0f)
        {
            __TrackPosition++;
        }
    }

    if (++DownsamplingCounter >= DownsamplingNumber)
    {
        for (int i = 0; i < FLOW_CHANNELS; i++)
        {
            SumX[i] = __SumX[i];
            SumY[i] = __SumY[i];
            __SumX[i] = 0;
            __SumY[i] = 0;
        }

        TrackPosition = __TrackPosition;

        DownsamplingCounter = 0;
        MeasurementCompleted++;
    }
}

void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef *hadc)
{
    process(&ADCBuffer[0]);
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    process(&ADCBuffer[FLOW_ADC_CHANNELS * ADC_NUM_OF_SAMPLES]);
}