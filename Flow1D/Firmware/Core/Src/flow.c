#include "flow.h"
#include "fast_math.h"
#include "main.h"

#define SENSITIVITY ((EXPECTED_SPEED_OF_SOUND * EXPECTED_SPEED_OF_SOUND) / (2.0f * M_2PI * US_FREQ * INTERSENSOR_DISTANCE))
#define FULL_SCALE_RANGE ((EXPECTED_SPEED_OF_SOUND * EXPECTED_SPEED_OF_SOUND) / (4.0f * US_FREQ * INTERSENSOR_DISTANCE))
		
/* Private functions -------------------------------------------------------*/
void getPhasor(uint16_t *adcBuffer, Complex_t *phasor);

/* Imported variables ------------------------------------------------------*/
extern ADC_HandleTypeDef hadc;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim21;
extern TIM_HandleTypeDef htim22;

/* Private variables -------------------------------------------------------*/
static volatile Flow_State_t State = FLOW_STATE_UNINIT;

// Static variables.
static uint16_t AdcBuffer[2 * SAMPLES_PER_MEASUREMENT];
static volatile uint8_t BufferIdx;
static volatile Complex_t Phasor[2];

/* Exported functions ------------------------------------------------------*/
void Flow_Init(void)
{
	State = FLOW_STATE_READY;
}

void Flow_Start(void)
{
	BufferIdx = 0;
	
	// Start ADC trigger & ultrasound generator.
	if (HAL_TIM_OC_Start(&htim2) != HAL_OK)
	{
		while(1);
	}
	
	// Start analog output timer.
	if (HAL_TIM_PWM_Start(&htim22, TIM_CHANNEL_2) != HAL_OK)
	{	
		while(1);
	}
	
 	// Start ADC.
	if (HAL_ADC_Start_DMA(&hadc1, AdcBuffer, sizeof(AdcBuffer)) != HAL_OK)
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
	if (HAL_TIM_Base_Stop(&htim2) != HAL_OK)
	{
		while(1);
	}
	
	// Stop analog output timer.
	if HAL_TIM_PWM_Start(&htim22, TIM_CHANNEL_2) != HAL_OK)
	{
		while(1);
	}
	
    State = FLOW_STATE_READY;
}

/* Callbacks ---------------------------------------------------------------*/
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc)
{
	if (State != FLOW_STATE_OPERATING)
		return;
		
	getPhasor(&AdcBuffer[BufferIdx & 0x01]* SAMPLES_PER_MEASUREMENT], &Phasor[BufferIdx & 0x01]);
	
	if (BufferIdx & 0x01)
	{
		HAL_GPIO_WritePin(DIR_GPIO_Port, DIR_Pin, GPIO_PIN_RESET);
		
		Complex_t resultant_phasor;
		Complex_Divide(&resultant_phasor, &Phasor[1], &Phasor[0]);
		
		float shift, wind_velocity;
		shift = Complex_Argument(&resultant_phasor);
		wind_velocity = shift * SENSITIVITY;
		
		uint16_t pulse;
		pulse = (1.0 + wind_velocity / FULL_SCALE_RANGE) * ((TIM22_RELOAD >> 1) - 1);
		
		__HAL_TIM_SET_COMPARE(&htim22, TIM_CHANNEL_2, pulse);
	}
	else
	{
		HAL_GPIO_WritePin(DIR_GPIO_Port, DIR_Pin, GPIO_PIN_SET);
	}
	
	BufferIdx++;
}

void getPhasor(uint16_t *adcBuffer, Complex_t *phasor)
{
	qint0_31_t phasor_real = 0;
	qint0_31_t phasor_img = 0;
	
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
	phasor->real = ((float)phasor_real) / ((1 << 12) * (SAMPLES_PER_PHASE_MEASUREMENT - DEAD_SAMPLES));
	phasor->img = ((float)phasor_img) / ((1 << 12) * (SAMPLES_PER_PHASE_MEASUREMENT - DEAD_SAMPLES));
}