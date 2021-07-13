#include "flow.h"
#include "fast_math.h"
#include "main.h"
#include "complex.h"
#include "qfplib.h"

#define SENSITIVITY 5.692033397278551f //((EXPECTED_SPEED_OF_SOUND * EXPECTED_SPEED_OF_SOUND) / (2.0f * M_2PI * US_FREQ * INTERSENSOR_DISTANCE))
#define FULL_SCALE_RANGE 17.88205030487805f // ((EXPECTED_SPEED_OF_SOUND * EXPECTED_SPEED_OF_SOUND) / (4.0f * US_FREQ * INTERSENSOR_DISTANCE))
		
/* Private functions -------------------------------------------------------*/
void process(uint8_t block);
void getPhasor(uint16_t *adcBuffer, Complex_t *phasor);

/* Imported variables ------------------------------------------------------*/
extern ADC_HandleTypeDef hadc;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim21;
extern TIM_HandleTypeDef htim22;

/* Private variables -------------------------------------------------------*/
static volatile Flow_State_t State = FLOW_STATE_UNINIT;

// Static variables.
static uint16_t AdcBuffer[2 * SAMPLES_PER_PHASE_MEASUREMENT];
static Complex_t Phasor[2];
static Complex_t Compensation = {0.9533833701892036f, 0.30176174284802226f};

/* Exported functions ------------------------------------------------------*/
void Flow_Init(void)
{
	State = FLOW_STATE_READY;
}

void Flow_Start(void)
{
	// Start analog output timer.
	if (HAL_TIM_PWM_Start(&htim22, TIM_CHANNEL_2) != HAL_OK)
	{	
		while(1);
	}
	
 	// Start ADC.
	if (HAL_ADC_Start_DMA(&hadc, (uint32_t *)AdcBuffer, (sizeof(AdcBuffer) / sizeof(uint16_t))) != HAL_OK)
	{
		while(1);
	}
	
	// Make ADC trigger timer ready to be triggered.
	if (HAL_TIM_PWM_Start(&htim21, TIM_CHANNEL_2) != HAL_OK)
	{
		while(1);
	}

	// Start operation.
	if (HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3) != HAL_OK)
	{
		while(1);
	}
	
	// Reset the transmit-receive direction.
	HAL_GPIO_WritePin(DIR_GPIO_Port, DIR_Pin, GPIO_PIN_RESET);
	
	State = FLOW_STATE_OPERATING;
}

void Flow_Execute(void)
{
}

void Flow_Stop(void)
{
	// Stop ADC trigger & ultrasound generator.
	if (HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_3) != HAL_OK)
	{
		while(1);
	}
	
	State = FLOW_STATE_READY;
}

/* Callbacks ---------------------------------------------------------------*/
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc)
{
	process(0);
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	process(1);
}

void process(uint8_t block)
{
	if (State != FLOW_STATE_OPERATING)
		return;
		
	getPhasor(&AdcBuffer[block * SAMPLES_PER_PHASE_MEASUREMENT], &Phasor[block]);
	
	if (block == 1)
	{
		HAL_GPIO_WritePin(DIR_GPIO_Port, DIR_Pin, GPIO_PIN_RESET);
		
		Complex_t resultant_phasor;
		Complex_Divide(&Phasor[1], &Phasor[0], &resultant_phasor);
		Complex_Multiply(&resultant_phasor, &Compensation, &resultant_phasor);
		
		float shift, wind_velocity;
		shift = Complex_Argument(&resultant_phasor);
		wind_velocity = qfp_fmul(shift, SENSITIVITY);
		
		uint16_t pulse;
		pulse = (uint16_t)qfp_float2uint(qfp_fmul(qfp_fadd(1.0f, qfp_fdiv(wind_velocity, FULL_SCALE_RANGE)),  
		qfp_int2float(TIM22_RELOAD >> 1)));
		
		__HAL_TIM_SET_COMPARE(&htim22, TIM_CHANNEL_2, pulse);
	}
	else
	{
		HAL_GPIO_WritePin(DIR_GPIO_Port, DIR_Pin, GPIO_PIN_SET);
	}
}

void getPhasor(uint16_t *adcBuffer, Complex_t *phasor)
{
	int32_t phasor_real = 0;
	int32_t phasor_img = 0;
	
	for (uint16_t i =  DEAD_SAMPLES; i < SAMPLES_PER_PHASE_MEASUREMENT; i+= 16)
	{
		phasor_real += adcBuffer[i];
		phasor_img -= adcBuffer[i+1];
		phasor_real -= adcBuffer[i+2];
		phasor_img += adcBuffer[i+3];

		phasor_real += adcBuffer[i+4];
		phasor_img -= adcBuffer[i+5];
		phasor_real -= adcBuffer[i+6];
		phasor_img += adcBuffer[i+7];

		phasor_real += adcBuffer[i+8];
		phasor_img -= adcBuffer[i+9];
		phasor_real -= adcBuffer[i+10];
		phasor_img += adcBuffer[i+11];
		
		phasor_real += adcBuffer[i+12];
		phasor_img -= adcBuffer[i+13];
		phasor_real -= adcBuffer[i+14];
		phasor_img += adcBuffer[i+15];
	}

	// Set return value.
	phasor->real = qfp_fdiv(qfp_int2float(phasor_real), qfp_int2float((1 << 12) * (SAMPLES_PER_PHASE_MEASUREMENT - DEAD_SAMPLES)));
	phasor->img = qfp_fdiv(qfp_int2float(phasor_img), qfp_int2float((1 << 12) * (SAMPLES_PER_PHASE_MEASUREMENT - DEAD_SAMPLES)));
}