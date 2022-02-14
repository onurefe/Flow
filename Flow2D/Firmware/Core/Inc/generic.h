#ifndef __GENERIC_H
#define __GENERIC_H

/* Includes ----------------------------------------------------------------*/
#include "stm32g0xx_hal.h"

/* Constants ---------------------------------------------------------------*/
#ifndef M_2PI
#define M_2PI 6.283185307179586f
#endif

#ifndef M_SQRT3_2
#define M_SQRT3_2 (M_SQRT_3 / 2.0f)
#endif

#ifndef M_PI
#define M_PI (M_2PI/2.0f)
#endif

#ifndef M_PI_2
#define M_PI_2 (M_PI/2.0f)
#endif


#ifndef M_PI_4
#define M_PI_4 (M_PI_2/2.0f)
#endif

#ifndef M_SQRT3
#define M_SQRT3 1.73205080757f
#endif

/* Typedefs ----------------------------------------------------------------*/
enum
{
    FALSE = 0,
    TRUE = !FALSE,
};
typedef uint8_t Bool_t;

typedef int64_t qint0_63_t;
typedef int32_t qint0_31_t;
typedef int16_t qint0_15_t;

#endif
