/*
* l_direction.h
* Gisi Musa
*/

#ifndef L_DIRECTION_H
#define L_DIRECTION_H
#include "allHeaders.h"

class l_direction: public Instruction
{
    public:
        l_direction();
        int parse(string args, int line);
        string read();
        virtual ~l_direction();

    private:
        tdirection dir;
        string on_fail;
};

#endif // L_DIRECTION_H