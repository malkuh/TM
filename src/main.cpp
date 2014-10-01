#include <iostream>
#include "TM.h"
#include "NTM.h"

typedef unsigned int uint;

using namespace std;

int main()
{
    bool test_d = false;
    bool test_nd = true;
    
    if (test_d)
    {
        cout << "Deterministic Turing machine simulation..." << endl;
        
        // setting parameters
        uint nr_stat = 3;
        uint nr_symbols = 2;
        uint nr_final_stat = 1;
        Action** table = new Action*[nr_stat-nr_final_stat];
        for (int i = 0; i < nr_stat-nr_final_stat; i++)
            table[i] = new Action[nr_symbols];
        
        //  2-state busy beaver
        
        table[0][0].state = 1;
        table[0][0].symbol = 1;
        table[0][0].move = true;
        
        table[0][1].state = 1;
        table[0][1].symbol = 1;
        table[0][1].move = false;
        
        table[1][0].state = 0;
        table[1][0].symbol = 1;
        table[1][0].move = false;
        
        table[1][1].state = 2;
        table[1][1].symbol = 1;
        table[1][1].move = true;
        
        // initialize the Turing machine
        TM M(nr_stat, nr_symbols, nr_final_stat, table);
        
        // let it run
        M.simulate(true);
        cout << M.get_steps() << endl;
        
        for (int i = 0; i < nr_stat-nr_final_stat; i++)
            delete[] table[i];
        delete[] table;
    }
    
    //////////////
    // Test NTM //
    //////////////
    
    if (test_nd)
    {
        cout << "Nondeterministic Turing  machine simulation..." << endl;
        
        // setting parameters
        uint nr_stat = 3;
        uint nr_symbols = 2;
        uint nr_final_stat = 1;
        
        // set up multidimensional array of lists of Actions
        list<Action>** action_list = new list<Action>*[nr_stat-nr_final_stat];
        for (int i = 0; i < nr_stat-nr_final_stat; i++)
            action_list[i] = new list<Action>[nr_symbols];
    
        // 2-state busy beaver with additional transition actions
        Action act = {1, 1, true};
        action_list[0][0].push_front(act);
        act.move = false;
        action_list[0][1].push_front(act);
        act.state = 0;
        action_list[1][0].push_front(act);
        act.state = 2;
        act.move = true;
        action_list[1][1].push_front(act);
        
        // add two additional actions
        act.state = 0;
        action_list[0][0].push_front(act);
        action_list[1][0].push_front(act);
        
        // initialize nondeterministic Turing machine
        NTM nM(nr_stat, nr_symbols, nr_final_stat, action_list);
        
        // let it run for some steps
//         nM.simulate(10, true);
        nM.simulate(30, true);
        
        cout << "Number of states: " << nM.get_nr_states() << endl;
        
        // clean up and delete the list of actions
        for (int i = 0; i < nr_stat-nr_final_stat; i++)
            delete[] action_list[i];
        delete[] action_list;
    }
    return 0;
}

/////////////////////////
// 2-state busy beaver //
/////////////////////////

//     table[0][0].state = 1;
//     table[0][0].symbol = 1;
//     table[0][0].move = true;
//     
//     table[0][1].state = 1;
//     table[0][1].symbol = 1;
//     table[0][1].move = false;
//     
//     table[1][0].state = 0;
//     table[1][0].symbol = 1;
//     table[1][0].move = false;
//     
//     table[1][1].state = 2;
//     table[1][1].symbol = 1;
//     table[1][1].move = true;

/////////////////////////
// 3-state busy beaver //
/////////////////////////

//     table[0][0].state = 1;
//     table[0][0].symbol = 1;
//     table[0][0].move = true;
//     
//     table[0][1].state = 2;
//     table[0][1].symbol = 1;
//     table[0][1].move = false;
//     
//     table[1][0].state = 0;
//     table[1][0].symbol = 1;
//     table[1][0].move = false;
//     
//     table[1][1].state = 1;
//     table[1][1].symbol = 1;
//     table[1][1].move = true;
//     
//     table[2][0].state = 1;
//     table[2][0].symbol = 1;
//     table[2][0].move = false;
//     
//     table[2][1].state = 3;
//     table[2][1].symbol = 1;
//     table[2][1].move = true;

/////////////////////////
// 4-state busy beaver //
/////////////////////////

//     table[0][0].state = 1;
//     table[0][0].symbol = 1;
//     table[0][0].move = true;
//     
//     table[0][1].state = 1;
//     table[0][1].symbol = 1;
//     table[0][1].move = false;
//     
//     table[1][0].state = 0;
//     table[1][0].symbol = 1;
//     table[1][0].move = false;
//     
//     table[1][1].state = 2;
//     table[1][1].symbol = 0;
//     table[1][1].move = false;
//     
//     table[2][0].state = 4;
//     table[2][0].symbol = 1;
//     table[2][0].move = true;
//     
//     table[2][1].state = 3;
//     table[2][1].symbol = 1;
//     table[2][1].move = false;
//     
//     table[3][0].state = 3;
//     table[3][0].symbol = 1;
//     table[3][0].move = true;
//     
//     table[3][1].state = 0;
//     table[3][1].symbol = 0;
//     table[3][1].move = true;

/////////////////////////
// 5-state busy beaver //
/////////////////////////

//     table[0][0].state = 1;
//     table[0][0].symbol = 1;
//     table[0][0].move = true;
//     
//     table[0][1].state = 2;
//     table[0][1].symbol = 1;
//     table[0][1].move = false;
//     
//     table[1][0].state = 2;
//     table[1][0].symbol = 1;
//     table[1][0].move = true;
//     
//     table[1][1].state = 1;
//     table[1][1].symbol = 1;
//     table[1][1].move = true;
//     
//     table[2][0].state = 3;
//     table[2][0].symbol = 1;
//     table[2][0].move = true;
//     
//     table[2][1].state = 4;
//     table[2][1].symbol = 0;
//     table[2][1].move = false;
//     
//     table[3][0].state = 0;
//     table[3][0].symbol = 1;
//     table[3][0].move = false;
//     
//     table[3][1].state = 3;
//     table[3][1].symbol = 1;
//     table[3][1].move = false;
//         
//     table[4][0].state = 5;
//     table[4][0].symbol = 1;
//     table[4][0].move = true;
//     
//     table[4][1].state = 0;
//     table[4][1].symbol = 0;
//     table[4][1].move = false;