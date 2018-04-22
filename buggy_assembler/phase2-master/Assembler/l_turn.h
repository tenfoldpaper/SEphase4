/*
* l_turn.h
* Gisi Musa
*/

#ifndef L_TURN_H
#define L_TURN_H
#include "allHeaders.h"

class l_turn: public Instruction
{
    public:
        l_turn();
        int parse(string args, int line);
        string read();
        virtual ~l_turn();

    private:
        tleftright lr;
};

#endif // L_TURN_H