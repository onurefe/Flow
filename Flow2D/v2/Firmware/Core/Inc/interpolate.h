#ifndef __INTERPOLATE_H
#define __INTERPOLATE_H

#ifdef __cplusplus
extern "C"
{
#endif
    
    extern float Interpolate_SecondOrderInterpolate(float *xdiff, float *ydiff, float relative_x);
    extern float Interpolate_FirstOrderInterpolate(float xdiff, float ydiff, float relative_x);

#ifdef __cplusplus
}
#endif

#endif