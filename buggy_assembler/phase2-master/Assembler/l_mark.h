/*
* l_mark.h
* Gisi Musa
*/

#ifndef L_MARK_H
#define L_MARK_H
#include "allHeaders.h"

class l_mark: public Instruction
{
    public:
        l_mark();
        int parse(string args, int line);
        string read();
        virtual ~l_mark();

    private:
        tmark mark;
};

#endif // L_MARK_H