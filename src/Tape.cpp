#include "Tape.h"

Tape::Tape()
{
    pos = 8;
    size = 16;
    right_expansion = 8;
    left_expansion = 8;
    start = 8;
    end = 8;
    content = new uint[16]();
//     for(int i = 0; i < 16; i++)
//         content[i] = 0;
}

// destructor
Tape::~Tape()
{
    delete[] content;
}

// copy constructor
Tape::Tape(const Tape& other)
{
    pos = other.pos;
    size = other.size;
    right_expansion = other.right_expansion;
    left_expansion = other.left_expansion;
    start = other.start;
    end = other.end;
    content = new uint[other.size];
    copy(other.content, other.content + other.size, content);
}

// assignment operator
Tape& Tape::operator= (const Tape & other)
{
    if (this != &other) // protect against invalid self-assignment
    {
        pos = other.pos;
        size = other.size;
        right_expansion = other.right_expansion;
        left_expansion = other.left_expansion;
        start = other.start;
        end = other.end;
        uint* new_content = new uint[other.size];
        copy(other.content, other.content + other.size, new_content);
        delete[] content;
        content = new_content;
    }
    return *this;
}

uint Tape::read() const
{
    return content[pos];
}

void Tape::write(uint symbol)
{
    content[pos] = symbol;
}

void Tape::move(bool move)
{
    if(move)
    {
        if (pos != size-1)
            pos++;
        else
        {
            expand_right();
            pos++;
        }
    }
    else
    {
        if (pos != 0)
            pos--;
        else
        {
            expand_left();
            pos--;
        }
    }
    if (pos > end)
        end = pos;
    if (pos < start)
        start = pos;
}

void Tape::print() const
{
    for(int i = start; i <= end; i++)
    {
        if ( i == pos )
            cout << "|" << content[i] << "|";
        else
            cout << content[i];
    }
    cout << endl;
}

// auxiliary functions
void Tape::expand_right()
{
    uint new_size = size + right_expansion;
    uint* new_content = new uint[new_size]();
    for(int i = start; i <= end; i++)
        new_content[i] = content[i];
    delete[] content;
    content = new_content;
    size = new_size;
    right_expansion *= 2;
}

void Tape::expand_left()
{
    uint new_size = size + left_expansion;
    uint* new_content = new uint[new_size]();
    for (int i = start+left_expansion; i <= end+left_expansion; i++)
        new_content[i] = content[i-left_expansion];
    delete[] content;
    content = new_content;
    size = new_size;
    pos += left_expansion;
    start += left_expansion;
    end += left_expansion;
    left_expansion *= 2;
}
