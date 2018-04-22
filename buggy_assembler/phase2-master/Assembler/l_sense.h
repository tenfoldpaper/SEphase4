/*
* l_sense.h
* Gisi Musa
*/

#ifndef L_SENSE_H
#define L_SENSE_H
#include "allHeaders.h"

class l_sense: public Instruction
{
    public:
        l_sense();
        int parse(string args, int line);
        string read();
        virtual ~l_sense();

    private:
        string dir;
        string cond;
        string on_fail;
};

#endif // L_SENSE_H