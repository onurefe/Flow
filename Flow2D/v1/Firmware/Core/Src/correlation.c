#include "correlation.h"
#include "config.h"
#include "interpolate.h"

/**
 * @brief Calculates the correlation score between two arrays. It searches the array y2 in array y1.
 * 
 */
float Correlation_GetScore(Complex_t *y1, Complex_t *y2, uint16_t window_start, uint16_t window_size, float y1_shift)
{
    Complex_t shifted_y1;
    float xdiff[2] = {1.0f, 1.0f};
    float y1realdiff[2];
    float y1imgdiff[2];
    Complex_t diff;
    Complex_t mean = {.real = 0.0f, .img = 0.0f};

    for (int32_t i = 0; i < window_size; i++)
    {
        y1realdiff[0] = y1[window_start + i + 1].real - y1[window_start + i].real;
        y1realdiff[1] = y1[window_start + i + 2].real - y1[window_start + i + 1].real;
        y1imgdiff[0] = y1[window_start + i + 1].img - y1[window_start + i].img;
        y1imgdiff[1] = y1[window_start + i + 2].img - y1[window_start + i + 1].img;

        shifted_y1.real = qfp_fadd(y1[window_start + i].real, Interpolate_SecondOrderInterpolate(xdiff, y1realdiff, y1_shift));
        shifted_y1.img = qfp_fadd(y1[window_start + i].img, Interpolate_SecondOrderInterpolate(xdiff, y1imgdiff, y1_shift));

        Complex_Divide(&shifted_y1, &y2[i], &diff);
        mean.real = qfp_fadd(diff.real, mean.real);
        mean.img = qfp_fadd(diff.img, mean.img);
    }

    mean.real = qfp_fdiv(mean.real, qfp_uint2float((uint32_t)window_size));
    mean.img = qfp_fdiv(mean.img, qfp_uint2float((uint32_t)window_size));

    float score;
    score = qfp_fmul(CORRELATION_SCORE_NORM_WEIGHT, Complex_Norm(&mean));
    score = qfp_fadd(score, qfp_fmul(CORRELATION_SCORE_PHASE_WEIGHT, mean.real));

    return score;
}