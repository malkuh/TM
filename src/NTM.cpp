#include "NTM.h"
    
NTM::NTM(uint arg_nr_states,
         uint arg_nr_symbols,
         uint arg_nr_final_states,
         list<Action>** arg_trans_actions) 
 : 
    nr_states(arg_nr_states),
    nr_symbols(arg_nr_symbols),
    nr_final_states(arg_nr_final_states),
    trans_actions(arg_trans_actions),
    nr_steps(0)
{
    // create first starting state and insert into the state list
    TM_State first;
    first.state = 0;
    tm_states.push_front(first);
}

// simulate NTM until it halts or nr_steps steps are reached
void NTM::simulate(uint max_nr_steps, bool verbose)
{
    uint c_symbol;
    uint c_state;
    while(nr_steps <= max_nr_steps) {
        list<TM_State> new_tm_states;
        if ( verbose ) {
            cout << "Nr steps: " << nr_steps << endl;
            cout << "There are " << tm_states.size() << " states" << endl;
        }
        for (list<TM_State>::const_iterator it = tm_states.begin();
             it != tm_states.end(); ++it) {
            c_symbol = it->tape.read();
            c_state = it->state;
            if ( !is_final_state(c_state) ) {
                for(list<Action>::const_iterator act_it =
                    trans_actions[c_state][c_symbol].begin();
                    act_it != trans_actions[c_state][c_symbol].end();
                    ++act_it) {
                    TM_State tms(*it);
                    tms.state = act_it->state;
                    tms.tape.write(act_it->symbol);
                    tms.tape.move(act_it->move);
                    new_tm_states.push_front(tms);
//                     if(verbose) {
//                         print(tms);
//                     }
                }
            }
        }
        nr_steps++;
        swap(tm_states, new_tm_states);
    }
    cout << "Done simulating!" << endl;
}

uint NTM::get_steps() const
{
    return nr_steps;
}

uint NTM::get_nr_states() const
{
    return tm_states.size();
}

bool NTM::is_final_state(uint state) const
{
    if (state >= nr_states - nr_final_states)
        return true;
    else
        return false;
}

// set input on the band
void NTM::set_input(uint* input, uint sz_input)
{
    TM_State* first = &(*tm_states.begin());
    // maybe change tape for every state in the list ...?
    for (int i = 0; i < sz_input; i++)
    {
        first->tape.write(input[i]);
        first->tape.move(true);
    }
    // move head back to original position
    for (int i = 0; i < sz_input; i++)
        first->tape.move(false);
}

// print current state and tape
void NTM::print() const
{
    cout << "Number of states: " << tm_states.size() << endl;
    for (list<TM_State>::const_iterator it = tm_states.begin();
         it != tm_states.end(); ++it) {
        print(*it);
    }
}

// prints single TM state
void NTM::print(const TM_State &tms) const
{
    cout << "State: " << tms.state << endl;
    tms.tape.print();
}
