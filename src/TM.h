// Turing Machine class

#ifndef _TM_H_
#define _TM_H_

#include <iostream>

#include "Action.h"
#include "Tape.h"

typedef unsigned int uint;

using namespace std;

class TM
{
public:
    // constructor
    TM(uint arg_nr_states,
       uint arg_nr_symbols,
       uint arg_nr_final_states,
       Action** arg_trans_actions);
    
    // simulate TM until it halts
    void simulate(bool verbose = false);
    // simulate TM until it halts or nr_steps steps are reached
    void simulate(uint max_nr_steps, bool verbose = false);
    
    void one_step();
    
    uint get_steps(); 
    
    // set input on the band
    void set_input(uint* input, uint sz_input);
    
    // print current state and tape
    void print();

private:
    
    bool is_final_state(uint state);
    // the set of states Q contains wlog the numbers 0 to nr_states-1
    // 0 is the starting state
    uint nr_states;
    // the alphabet Gamma contains the numbers 0 to nr_symbols-1
    // 0 is the blank symbol
    uint nr_symbols;
    // input symbols Sigma, wlog the numbers from 0 to nr_input_symbols-1
    uint nr_input_symbols;
    // F \ Q is the set of final or accepting states.
    uint nr_final_states;
    // delta: (Q\F) x \Gamma -> (Q x \Gamma x {L,R} is a partial function 
    // called the transition function, where L is left shift, R is right shift.
    Action** trans_actions;
    
    // tape and current state
    Tape tape;
    uint c_state;
    uint nr_steps;

};

#endif
