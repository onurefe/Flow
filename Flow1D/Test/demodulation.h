#ifndef __DEMODULATION_H
#define __DEMODULATION_H

#include "defines.h"
#include "complex.h"

#define SYS_FREQ 32000000
#define US_FREQ 40000
#define SAMPLES_PER_CARRIER_PERIOD 4

#define INTERSENSOR_DISTANCE 4.1f
#define EXPECTED_SPEED_OF_SOUND 34600.25f
#define SAMPLES_PER_PHASE_MEASUREMENT 800
#define DEAD_TIME (1.5f * INTERSENSOR_DISTANCE / EXPECTED_SPEED_OF_SOUND)
#define DEAD_SAMPLES (((uint16_t)((float)SAMPLES_PER_CARRIER_PERIOD * US_FREQ * DEAD_TIME) / 16) * 16)

extern void Demodulation_GetPhasor(uint16_t *adcBuffer, Complex_t *phasor);

#endif