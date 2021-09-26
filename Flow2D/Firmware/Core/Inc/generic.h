#ifndef __GENERIC_H
#define __GENERIC_H

/* Includes ----------------------------------------------------------------*/
#include "main.h"

/* Constants ---------------------------------------------------------------*/
#ifndef M_2PI
#define M_2PI 6.283185307179586f
#endif

#ifndef M_PI
#define M_PI 3.141592653589793f
#endif

#ifndef M_PI_2
#define M_PI_2 1.5707963267948966f
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
