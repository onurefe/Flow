#ifndef __FLOW_H
#define __FLOW_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "generic.h"
#include "complex.h"
#include "config.h"

/* Exported constants ------------------------------------------------------*/
#define FLOW_CHANNELS 3
#define FLOW_ADC_CHANNELS 3
#define FLOW_INTERSENSOR_DISTANCE_IN_METERS 0.034641f
#define FLOW_RUN_SKIP 1
#define FLOW_CALIBRATION_SKIP 1
#define FLOW_SEARCHING_SKIP 1
#define FLOW_CALIBRATION_DOWNSAMPLING_NUMBER 50
#define FLOW_SEARCHING_DOWNSAMPLING_NUMBER 25
#define FLOW_RUN_GAIN (FLOW_INTERSENSOR_DISTANCE_IN_METERS * 6.283185307179586f * ((float)US_RUN_FREQ))
#define FLOW_SEARCH_POINTS 50
#define CHOOSE_BETWEEN_TOP 19

    /* Exported types ----------------------------------------------------------*/
    enum
    {
        FLOW_STATUS_READY = 0,
        FLOW_STATUS_CALIBRATING = 1,
        FLOW_STATUS_SEARCHING = 2,
        FLOW_STATUS_RUNNING = 3
    };
    typedef uint8_t Flow_Status_t;

    typedef struct
    {
        Complex_t calibrationVector[RESP_FUNC_SAMPLE_POINTS][FLOW_CHANNELS];
        float speedOfSound;
        uint32_t flashCode; // Variable to pad the struct to double words.
    } Flow_Calibration_t;

    typedef struct
    {
        float velocityFilterTc;
        float temperatureFilterTc;
        uint16_t downsamplingNumber;
    } Flow_RunParams_t;

    typedef void (*Flow_CalibrationCompletedCallback_t)(Flow_Calibration_t *calibrationResult);
    typedef void (*Flow_SearchCompletedCallback_t)(float search2CalibrationOffset, float correlation, float temperature);
    typedef void (*Flow_MeasurementCompletedCallback_t)(float vx, float vy, float temperature);

    /* Exported functions ------------------------------------------------------*/
    extern void Flow_Init(void);
    extern Bool_t Flow_Calibrate(Flow_Calibration_t *calibrationResult, float speedOfSound,
                                 Flow_CalibrationCompletedCallback_t calibrationCompletedCb);
    extern Bool_t Flow_Run(Flow_Calibration_t *calibration, float searchCalibrationOffset,
                           Flow_RunParams_t *params, Flow_MeasurementCompletedCallback_t measurementCompletedCb);
    extern Bool_t Flow_SearchSpeedOfSound(Flow_Calibration_t *calibration,
                                          Flow_SearchCompletedCallback_t searchCompletedCb);
    extern void Flow_Execute(void);
    extern void Flow_Stop(void);

#ifdef __cplusplus
}
#endif

#endif