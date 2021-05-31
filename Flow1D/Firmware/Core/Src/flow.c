#include "flow.h"
#include "fast_math.h"

#define INTERSPACE_SENSOR_DISTANCE 4.1f
#define EXPECTED_SPEED_OF_SOUND 34600.25f
#define CIRCUITRY_RELATED_PHASE_SHIFT 0.67f
#define MEASUREMENT_FREQ 100
#define SAMPLES_PER_MEASUREMENT ((US_FREQ * SAMPLES_PER_CYCLE) / MEASUREMENT_FREQ)
#define DEAD_SAMPLES ((1.5 * SAMPLES_PER_CYCLE * US_FREQ * INTERSPACE_SENSOR_DISTANCE) / EXPECTED_SPEED_OF_SOUND) 

/* Private functions -------------------------------------------------------*/

/* Imported variables ------------------------------------------------------*/
extern ADC_HandleTypeDef hadc;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim21;
extern TIM_HandleTypeDef htim22;

/* Private variables -------------------------------------------------------*/
static volatile Flow_State_t State = FLOW_STATE_UNINIT;

// Static variables.
static uint16_t AdcBuffer[SAMPLES_PER_MEASUREMENT];
static volatile uint8_t BufferIdx;

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
	
 	// Start ADC.
	if (HAL_ADC_Start_DMA(&hadc1, AdcBuffer, sizeof(AdcBuffer)) != HAL_OK)
	{
		while(1);
	}
	
	// Reset the direction of soundwaves.
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
	
    State = FLOW_STATE_READY;
}

void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc)
{
	if (State != FLOW_STATE_OPERATING)
		return;
		
	static float pm0_real[2], pm0_img[2], pm1_real[2], pm1_img[2];
	
	// Process data for half-wave.
	getHalfHarmonics(AdcBuffer, BufferIdx, &pm0_real[BufferIdx], &pm0_img[BufferIdx], 
	&pm1_real[BufferIdx], &pm1_img[BufferIdx]);
	
	if (BufferIdx & 0x01)
	{
		// Measurement completed.
		float pm0_real, pm0_img, pm1_real, pm1_img;
		
		pm0_real = pm0_real[0] + pm0_real[1];
		pm0_img = pm0_img[0] + pm0_img[1];
		
		pm1_real = pm1_real[0] + pm1_real[1];
		pm1_img = pm1_img[0] + pm1_img[1];
	 
	 	HAL_GPIO_WritePin(DIR_GPIO_Port, DIR_Pin, GPIO_PIN_RESET);
	}
	else
	{
		HAL_GPIO_WritePin(DIR_GPIO_Port, DIR_Pin, GPIO_PIN_SET);
	}
	
	BufferIdx = (BufferIdx + 1) & 0x01;
}

/* Callbacks ---------------------------------------------------------------*/


/* Utilities ---------------------------------------------------------------*/
void getHalfHarmonics(uint16_t *adcBuffer, Bool_t secondHalf, float *m0Real, float *m0Img, float *m1Real, float *m1Img)
{
   	qint0_31_t qm0_real = 0;
    qint0_31_t qm0_img = 0;
    qint0_31_t qm1_real = 0;
    qint0_31_t qm1_img = 0;
    
  	uint16_t quadoffset = SAMPLES_PER_MEASUREMENT >> 2;
    qint0_15_t sine, cosine;
    uint16_t sidx = DEAD_SAMPLES;
    uint16_t *adcbuff = adcBuffer[secondHalf * SAMPLES_PER_MEASUREMENT];
    
    if (!secondHalf)
    {
    	while (sidx < quadoffset)
    	{
    		sine = sinetable[sidx];
    		cosine = sinetable[quadoffset - (sidx + 1)];
    	
    		qm0_real += adcbuff[sidx];
			qm0_real += adcbuff[sidx + quadoffset];
		
			qm1_real += (adcbuff[sidx] * cosine) >> 6;
	    	qm1_img -= (adcbuff[sidx] * sine) >> 6;
	    
	   		qm1_real -= (adcbuff[sidx + quadoffset] * sine) >> 6;
	    	qm1_img -= (adcbuff[sidx + quadoffset] * cosine) >> 6;
	   	
	   		sidx++;
	    
		    qm0_img -= adcbuff[sidx];
			qm0_img -= adcbuff[sidx + quadoffset];
			 
			qm1_real -= (adcbuff[sidx] * sine) >> 6;
			qm1_img -= (adcbuff[sidx] * cosine) >> 6;
		   
		    qm1_real -= (adcbuff[sidx + quadoffset] * cosine) >> 6;
		   	qm1_img += (adcbuff[sidx + quadoffset] * sine) >> 6;
		    
			sidx++;
	    
		    qm0_real -= adcbuff[sidx];
			qm0_real -= adcbuff[sidx + quadoffset];
			
			qm1_real -= (adcbuff[sidx] * cosine) >> 6;
		    qm1_img += (adcbuff[sidx] * sine) >> 6;
		    
		   	qm1_real += (adcbuff[sidx + quadoffset] * sine) >> 6;
		    qm1_img += (adcbuff[sidx + quadoffset] * cosine) >> 6;
		   	
		   	sidx++;
	    
		    qm0_img += adcbuff[sidx];
			qm0_img += adcbuff[sidx + quadoffset];
		
			qm1_real += (adcbuff[sidx] * sine) >> 6;	
			qm1_img += (adcbuff[sidx] * cosine) >> 6;
		    
		    qm1_real += (adcbuff[sidx + quadoffset] * cosine) >> 6;
		   	qm1_img -= (adcbuff[sidx + quadoffset] * sine) >> 6;
		    
		   	sidx++;
    	}
    }
    else
    {
    	while (sidx < quadoffset)
	    {
	    	sine = sinetable[sidx];
	    	cosine = sinetable[quadoffset - (sidx + 1)];
	    	
	    	qm0_real += adcbuff[sidx];
			qm0_real += adcbuff[sidx + quadoffset];
			
			qm1_real -= (adcbuff[sidx] * cosine) >> 6;
		    qm1_img += (adcbuff[sidx] * sine) >> 6;
		    
		   	qm1_real += (adcbuff[sidx + quadoffset] * sine) >> 6;
		    qm1_img += (adcbuff[sidx + quadofset] * cosine) >> 6;
		   	
		   	sidx++;
		    
		    qm0_img -= adcbuff[sidx];
			qm0_img -= adcbuff[sidx + quadoffset];
			 
			qm1_real += (adcbuff[sidx] * sine) >> 6;
			qm1_img += (adcbuff[sidx] * cosine) >> 6;
		   
		    qm1_real += (adcbuff[sidx + quadoffset] * cosine) >> 6;
		   	qm1_img -= (adcbuff[sidx + quadoffset] * sine) >> 6;
		    
		   	sidx++;
		    
		    qm0_real -= adcbuff[sidx];
			qm0_real -= adcbuff[sidx + quadoffset];
			
			qm1_real += (adcbuff[sidx] * cosine) >> 6;
		    qm1_img -= (adcbuff[sidx] * sine) >> 6;
		    
		   	qm1_real -= (adcbuff[sidx + quadoffset] * sine) >> 6;
		    qm1_img -= (adcbuff[sidx + quadoffset] * cosine) >> 6;
		   	
		   	sidx++;
		    
		    qm0_img += adcbuff[sidx];
			qm0_img += adcbuff[sidx + quadoffset];
		
			qm1_real -= (adcbuff[sidx] * sine) >> 6;	
			qm1_img -= (adcbuff[sidx] * cosine) >> 6;
		    
		    qm1_real -= (adcbuff[sidx + quadoffset] * cosine) >> 6;
		   	qm1_img += (adcbuff[sidx + quadoffset] * sine) >> 6;
		        
		    sidx++;
	    }
    }
    
    // Scale m0 components.
    qm0_real = qm0_real << 9;
    qm0_img = qm0_img << 9;
    
    // Set return value.
    *m0Real = qm0_real;
    *m0Img = qm0_img;
    *m1Real = qm1_real;
    *m1Img = qm1_img;
}