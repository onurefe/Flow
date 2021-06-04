/* -*- C -*- */
#include "defines.h"
#include "demodulation.h"
#include "math.h"

#define M_PI 3.14159265358979323846

int main()
{
    double wc = 2.0 * M_PI * 40000.0;
    double wm = 2.0 * M_PI * 100.0;
    double fs = 160000.0;
    uint16_t buff[SAMPLES_PER_MEASUREMENT];
    
    for (uint16_t i = 0; i < SAMPLES_PER_MEASUREMENT; i++)
    {
        buff[i] = sin(((1.0 * i) / fs) * wc) * sin(((1.0 * i) / fs) * wm);
    }
    
    float m0_real, m0_img, m1_real, m1_img;
    getHalfHarmonics(buff, FALSE, &m0_real, &m0_img, &m1_real, &m1_img);
    
    float m0_real2, m0_img2, m1_real2, m1_img2;
    getHalfHarmonics(buff, TRUE, &m0_real2, &m0_img2, &m1_real2, &m1_img2);
    
    print("m0=(%f, %fj) m1=(%f, %fj)", (m0_real + m0_real2), (m0_img + m0_img2), (m1_real + m1_real2), 
          (m1_img + m1_img2))
    
    return 0;
}