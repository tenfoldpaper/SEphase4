/*
* l_pickup.h
* Gisi Musa
*/

#ifndef L_PICKUP_H
#define L_PICKUP_H
#include "allHeaders.h"

class l_pickup: public Instruction
{
    public:
        l_pickup();
        int parse(string args, int line);
        string read();
        virtual ~l_pickup();

    private:
        string on_fail;
};

#endif // L_PICKUP_H