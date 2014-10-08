#include "TM.h"

// constructor
TM::TM(uint arg_nr_states, uint arg_nr_symbols,
       uint arg_nr_final_states,
       Action** arg_trans_actions) 
 : 
    nr_states(arg_nr_states),
    nr_symbols(arg_nr_symbols),
    nr_final_states(arg_nr_final_states),
    trans_actions(arg_trans_actions),
    nr_steps(0),
    c_state(0){}

// simulate TM until it halts
void TM::simulate(bool verbose)
{
    while(!is_final_state(c_state)) {
        one_step();
        if(verbose)
            print();
    }
    cout << "Done!" << endl;
}

// simulate TM until it halts or nr_steps steps are reached
void TM::simulate(uint max_nr_steps, bool verbose)
{
    while(!is_final_state(c_state) && nr_steps <= max_nr_steps) {
        one_step();
        if(verbose)
            print();
     }
    cout << "Done!" << endl;
}

// simulate one step of the Turing machine
void TM::one_step()
{
    Action c_action = trans_actions[c_state][tape.read()];
    c_state = c_action.state;
    tape.write(c_action.symbol);
    tape.move(c_action.move);
    nr_steps++;
}

bool TM::is_final_state(uint state) const
{
    if (state >= nr_states - nr_final_states)
        return true;
    else
        return false;
}

uint TM::get_steps() const
{
    return nr_steps;
}

// set input on the band
void TM::set_input(uint* input, uint sz_input)
{
    for (int i = 0; i < sz_input; i++)
    {
        tape.write(input[i]);
        tape.move(true);
    }
    for (int i = 0; i < sz_input; i++)
        tape.move(false);
}

// print current state and tape
void TM::print() const
{
    cout << "State: " << c_state << endl;
    tape.print();
}