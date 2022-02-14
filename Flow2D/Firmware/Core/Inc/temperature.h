#ifndef __TEMP_H
#define __TEMP_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ----------------------------------------------------------------*/
#include "config.h"
#include "qfplib.h"
#include "generic.h"

    /* Exported functions ------------------------------------------------------*/
    static inline float Temperature_GetSpeedOfSound(float temperature)
    {
        return qfp_fmul(331.3f, qfp_fsqrt(qfp_fadd(1.0f, qfp_fdiv(temperature, 273.15f))));
    }

    static inline float Temperature_GetTemperature(float speedOfSound)
    {
        float norm_vel;
        norm_vel = qfp_fdiv(speedOfSound, 331.3f);
        
        return qfp_fmul(273.15f, qfp_fsub(qfp_fmul(norm_vel, norm_vel), 1.0f));
    }

#ifdef __cplusplus
}
#endif

#endif