#ifndef _TM_State_H_
#define _TM_State_H_

#include "Tape.h"

typedef unsigned int uint;

struct TM_State
{
    // tape and current state
    Tape tape;
    uint state;
};

#endif