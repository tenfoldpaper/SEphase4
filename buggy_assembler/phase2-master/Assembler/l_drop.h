/*
* l_drop.h
* Gisi Musa
*/

#ifndef L_DROP_H
#define L_DROP_H
#include "allHeaders.h"

class l_drop: public Instruction
{
    public:
        l_drop();
        int parse(string args, int line);
        string read();
        virtual ~l_drop();
};

#endif // L_DROP_H