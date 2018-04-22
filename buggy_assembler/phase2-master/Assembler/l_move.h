/*
* l_move.h
* Gisi Musa
*/

#ifndef L_MOVE_H
#define L_MOVE_H
#include "allHeaders.h"

class l_move: public Instruction
{
    public:
        l_move();
        int parse(string args, int line);
        string read();
        virtual ~l_move();

    private:
        string on_fail;
};

#endif // L_MOVE_H