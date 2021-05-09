#ifndef __GLOBAL_DEFINITIONS_H
#define __GLOBAL_DEFINITIONS_H

/* Includes ----------------------------------------------------------------*/
#include "main.h"

/* Configuration -----------------------------------------------------------*/

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

#endif
