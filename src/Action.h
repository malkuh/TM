#ifndef _Action_H_
#define _Action_H_

typedef unsigned int uint;

struct Action
{
    uint state;
    uint symbol;
    bool move;
};

#endif