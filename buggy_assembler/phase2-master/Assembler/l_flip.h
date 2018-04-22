/*
* l_flip.h
* Gisi Musa
*/

#ifndef L_FLIP_H
#define L_FLIP_H
#include "allHeaders.h"

class l_flip: public Instruction
{
    public:
        l_flip();
        int parse(string args, int line);
        string read();
        virtual ~l_flip();

    private:
        int p;
        string on_fail;
};

#endif // L_FLIP_H