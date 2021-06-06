/* -*- C -*- */

#include "demodulation.h"

void Demodulation_GetPhasor(uint16_t *adcBuffer, Complex_t *phasor)
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