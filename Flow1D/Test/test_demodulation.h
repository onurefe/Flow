#include "defines.h"

#ifndef __DEMODULATION_H
#define __DEMODULATION_H

#define SYS_FREQ 32000000
#define US_FREQ 40000
#define SAMPLES_PER_CYCLE 4

#define INTERSENSOR_DISTANCE 4.1f
#define EXPECTED_SPEED_OF_SOUND 34600.25f
#define CIRCUITRY_RELATED_PHASE_SHIFT 0.67f
#define MEASUREMENT_FREQ 100
#define SAMPLES_PER_MEASUREMENT ((US_FREQ * SAMPLES_PER_CYCLE) / MEASUREMENT_FREQ)
#define DEAD_SAMPLES ((1.5 * SAMPLES_PER_CYCLE * US_FREQ * INTERSENSOR_DISTANCE) / EXPECTED_SPEED_OF_SOUND)

void getHalfHarmonics(uint16_t *adcBuffer, Bool_t secondHalf, float *m0Real, float *m0Img, float *m1Real, float *m1Img);

#endif