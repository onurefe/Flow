#include <stdio.h>

#ifndef __DEFINES_H
#define __DEFINES_H

typedef unsigned int uint32_t;
typedef int int32_t;
typedef unsigned short int uint16_t;
typedef short int int16_t;

typedef int32_t qint0_31_t;
typedef int16_t qint0_15_t;

typedef enum
{
    FALSE = 0,
    TRUE = !FALSE
} Bool_t;

#endif