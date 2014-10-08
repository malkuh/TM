// non-deterministic Turing Machine class

#ifndef _NTM_H_
#define _NTM_H_

#include <iostream>
#include <list>

#include "Action.h"
#include "Tape.h"
#include "TM_State.h"

typedef unsigned int uint;

using namespace std;

class NTM
{
public:
    // Constructor
    NTM(uint arg_nr_states, uint arg_nr_symbols, uint arg_nr_final_states,
    list<Action>** arg_trans_actions);
        
    // simulate TM until it halts or nr_steps steps are reached
    void simulate(uint max_nr_steps, bool verbose = false);
    
    // auxiliary functions
    uint get_steps() const;
    uint get_nr_states() const;
    
    // set input on the band
    void set_input(uint* input, uint sz_input);
    
    // print current state and tape
    void print() const;
    void print(const TM_State &tms) const;

private:
    
    bool is_final_state(uint state) const;
    // the set of states Q contains wlog the numbers 0 to nr_states-1
    // 0 is the starting state
    uint nr_states;
    // the alphabet Gamma contains the numbers 0 to nr_symbols-1
    // 0 is the blank symbol
    uint nr_symbols;
    // input symbols Sigma, wlog the numbers from 0 to nr_input_symbols-1
    uint nr_input_symbols;
    // F \subseteq Q is the set of final or accepting states.
    uint nr_final_states;
    // delta \subset (Q\F) x \Gamma x (Q x \Gamma x {L,R} is a relation,
    // where L is left shift, R is right shift.
    list<Action>** trans_actions;
    
    // number of steps run
    uint nr_steps;
    
    // list of states
    list<TM_State> tm_states;
};

#endif
