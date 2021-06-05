/* -*- C -*- */
#include "stdio.h"
#include "defines.h"
#include "demodulation.h"
#include "math.h"

#define M_PI 3.14159265358979323846
static uint16_t buff[SAMPLES_PER_MEASUREMENT];

int main()
{
    double wc = 2.0 * M_PI * 40000.0;
    double wr = 2.0 * M_PI * 100.0;
    double fs = 160000.0;
    float t;

    for (uint16_t i = 0; i < SAMPLES_PER_MEASUREMENT; i++)
    {
        t = ((float)i / fs);
        buff[i] = (uint16_t)((1 << 12) * (0.50f + (0.45 * sin(M_PI / 2 + wr * t)) * cos(wc * t)));
    }
    
    float m0_real = 0.0, m0_img = 0.0, m1_real = 0.0, m1_img = 0.0;
    getHalfHarmonics(buff, FALSE, &m0_real, &m0_img, &m1_real, &m1_img);
    
    float m0_real2 = 0.0, m0_img2 = 0.0, m1_real2 = 0.0, m1_img2 = 0.0;
    getHalfHarmonics(&buff[SAMPLES_PER_MEASUREMENT >> 1], TRUE, &m0_real2, &m0_img2, &m1_real2, &m1_img2);
    
    printf("m0=(%f, %fj) m1=(%f, %fj) \r\n", (m0_real + m0_real2), (m0_img + m0_img2), (m1_real + m1_real2), 
    (m1_img + m1_img2));
    
    return 0;
}