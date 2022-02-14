#ifndef __FAST_MATH
#define __FAST_MATH

#include "qfplib.h"
#include "generic.h"

#ifdef __cplusplus
extern "C" {
#endif

inline float FastMath_Abs(float x)
{
    if (x >= 0.0f)
    {
        return x;
    }
    else
    {
        return -x;
    }
}

inline float FastMath_approxAtan(float z)
{
    return qfp_fmul(qfp_fsub((M_PI_4 + 0.273f), qfp_fmul(FastMath_Abs(z), 0.273f)), z);
}

inline float FastMath_Atan2(float y, float x)
{
    if (x != 0.0f)
    {   
        if (FastMath_Abs(x) > FastMath_Abs(y))
        {
            float z = qfp_fdiv(y, x);
            if (x > 0.0f)
            {
                // atan2(y,x) = atan(y/x) if x > 0
                return FastMath_approxAtan(z);
            }
            else if (y >= 0.0f)
            {
                // atan2(y,x) = atan(y/x) + PI if x < 0, y >= 0
                return (qfp_fadd(FastMath_approxAtan(z), M_PI));
            }
            else
            {
                // atan2(y,x) = atan(y/x) - PI if x < 0, y < 0
                return (qfp_fadd(FastMath_approxAtan(z), -M_PI));
            }
        }
        else // Use property atan(y/x) = PI/2 - atan(x/y) if |y/x| > 1.
        {
            float z = qfp_fdiv(x, y);
            if (y > 0.0f)
            {
                // atan2(y,x) = PI/2 - atan(x/y) if |y/x| > 1, y > 0
                return qfp_fsub(M_PI_2, FastMath_approxAtan(z));
            }
            else
            {
                // atan2(y,x) = -PI/2 - atan(x/y) if |y/x| > 1, y < 0
                return qfp_fsub(-M_PI_2, FastMath_approxAtan(z));
            }
        }
    }
    else
    {
        if (y > 0.0f) // x = 0, y > 0
        {
            return M_PI_2;
        }
        else if (y < 0.0f) // x = 0, y < 0
        {
            return -M_PI_2;
        }
    }
    return 0.0f; // x,y = 0. Could return NaN instead.
}

#ifdef __cplusplus
}
#endif

#endif