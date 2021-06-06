/* -*- C -*- */
#include "stdio.h"
#include "defines.h"
#include "demodulation.h"
#include "complex.h"
#include "math.h"
#include "stdlib.h"

#define M_PI 3.14159265358979323846

static uint16_t buff[SAMPLES_PER_PHASE_MEASUREMENT << 1];

int main()
{
    double w = 2.0 * M_PI * 40000.0;
    double fs = 160000.0;
    float d = INTERSENSOR_DISTANCE;
    float u = EXPECTED_SPEED_OF_SOUND;
    float v = 0.1;

    srand(time(NULL));   // Initialization, should only be called once.

    for (uint16_t i = 0; i < SAMPLES_PER_PHASE_MEASUREMENT / 2; i++)
    {
        float t;
        t = ((float)i / fs);
        unsigned int r = rand();
        r = r % 1024;
        buff[i] = (uint16_t)((1 << 12) * (((float)r / (1 << 21)) + 0.50f + 0.45 * cos(w*d/(u-v) + w * t)));
    }

    for (uint16_t i = SAMPLES_PER_PHASE_MEASUREMENT; i < (2 * SAMPLES_PER_PHASE_MEASUREMENT); i++)
    {
        float t;
        t = ((float)i / fs);
        unsigned int r = rand();
        r = r % 1024;
        buff[i] = (uint16_t)((1 << 12) * (((float)r / (1 << 21)) + 0.50f + 0.45 * cos(w*d/(u+v) + w * t)));
    }

    Complex_t m0, m1;
    Demodulation_GetPhasor(buff, &m0);
    Demodulation_GetPhasor(&buff[SAMPLES_PER_PHASE_MEASUREMENT], &m1);

    printf("Phase diff: %f \r\n", w*d/(u-v) - w*d/(u+v));
    printf("m0:(%f, %fj) \r\n", m0.real, m0.img);
    printf("m1:(%f, %fj) \r\n", m1.real, m1.img);
    
    Complex_t r;
    Complex_Divide(&m0, &m1, &r);
    printf("r:(%f, %fj \r\n)", r.real, r.img);
    printf("Arg:%f \r\n", atan2(r.img, r.real));
    printf("v:%f \r\n", (atan2(r.img, r.real) * u * u) /(2*w*d));
    
    return 0;
}