#ifndef __CORRELATION_H
#define __CORRELATION_H

#include "generic.h"
#include "qfplib.h"
#include "complex.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /**
 * @brief Calculates the correlation score between two complex sampled functions. y2 is scaled
 * in the horizontal axis.
 */
    extern float Correlation_GetScore(Complex_t *y1, Complex_t *y2, float scale_shift);

#ifdef __cplusplus
}
#endif

#endif