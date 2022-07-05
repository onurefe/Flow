#ifndef __INTERPOLATE_H
#define __INTERPOLATE_H

#include "generic.h"
#include "config.h"
#include "qfplib.h"
#include "complex.h"

#ifdef __cplusplus
extern "C"
{
#endif
    static inline float Interpolate_SecondOrderInterpolate(float *xdiff, float *ydiff, float relative_x)
    {
        float b, c;
        float result;

        // Calculate coefficients.
        b = qfp_fdiv(ydiff[0], xdiff[0]);
        c = qfp_fdiv(qfp_fsub(qfp_fdiv(ydiff[1], xdiff[1]), qfp_fdiv(ydiff[0], xdiff[0])), qfp_fadd(xdiff[1], xdiff[0]));

        result = c;
        result = qfp_fmul(result, qfp_fsub(relative_x, xdiff[0]));
        result = qfp_fadd(result, b);
        result = qfp_fmul(result, relative_x);

        return result;
    }

    static inline float Interpolate_FirstOrderInterpolate(float xdiff, float ydiff, float relative_x)
    {
        return qfp_fmul(ydiff, qfp_fdiv(relative_x, xdiff));
    }
#ifdef __cplusplus
}
#endif

#endif