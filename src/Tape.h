// Tape class simulates a tape that can be moved, read and written to.

#ifndef _TAPE_H_
#define _TAPE_H_

#include <iostream>

typedef unsigned int uint;

using namespace std;

class Tape
{
public:
    // at initialization the tape contains only zeros.
    Tape();
    // deconstructor for deletion of array
    ~Tape();
    /** copy constructor **/
    Tape(const Tape& other);

    /** assignment operator */
    Tape& operator= (const Tape & other);
    
    /** methods for manipulating the tape and print out **/
    // write symbol to current position
    void write(uint symbol);
    // move right (true) or left (false)
    void move(bool move);
    // read symbol currently beneath the head
    uint read() const;
    // prints all positions the head has been
    // marks where the head is currently
    void print() const;
    
private:
    /** auxiliary functions **/
    // reserve larger size array for tape content to the right
    void expand_right();
    // reserve larger size array for tape content to the left
    void expand_left();
    
    /** variables **/
    // the size of the memory allocated for the content
    uint size;
    // the pointer to the content
    uint* content;
    // the current position
    uint pos;
    // the actual memory used by the tape
    uint start;
    uint end;
    // The sizes for the next expansion;
    // grow by a factor of 2 with every expansion.
    uint right_expansion;
    uint left_expansion;
};

#endif
