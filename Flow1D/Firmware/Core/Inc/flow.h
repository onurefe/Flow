#ifndef __FLOW_H
#define __FLOW_H

#include "global.h"

enum
{
    FLOW_STATE_UNINIT = 0,
    FLOW_STATE_READY,
    FLOW_STATE_OPERATING
};
typedef uint8_t Flow_State_t;

extern void Flow_Init(void);
extern void Flow_Start(void);
extern void Flow_Stop(void);

#endif