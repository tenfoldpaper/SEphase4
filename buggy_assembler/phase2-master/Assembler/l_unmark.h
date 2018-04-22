/*
* l_unmark.h
* Gisi Musa
*/

#ifndef L_UNMARK_H
#define L_UNMARK_H
#include "allHeaders.h"

class l_unmark: public Instruction
{
    public:
        l_unmark();
        int parse(string args, int line);
        string read();
        virtual ~l_unmark();

    private:
        tmark mark;
};

#endif // L_UNMARK_H