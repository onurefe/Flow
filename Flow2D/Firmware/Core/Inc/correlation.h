#ifndef __CORRELATION_H
#define __CORRELATION_H

#include "generic.h"
#include "qfplib.h"
#include "complex.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Calculates the correlation score between two arrays. It searches the array y2 in array y1.
 * 
 */
extern float Correlation_GetScore(Complex_t *y1, Complex_t *y2, uint16_t window_start, uint16_t window_size, float y1_shift);

/**
 * @brief Calculates the norm of an array.
 * 
 */
extern void Correlation_L2Norm(Complex_t *y, uint16_t length, float *realNorm, float *imgNorm);

/**
 * @brief Calculates the mean of an array.
 * 
 */
extern void Correlation_Mean(Complex_t *y, uint16_t length, float *realMean, float *imgMean);

#ifdef __cplusplus
}
#endif

#endif