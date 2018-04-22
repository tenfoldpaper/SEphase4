/*
* l_default.h
* Gisi Musa
*/

#ifndef L_DEFAULT_H
#define L_DEFAULT_H


class l_default: public Instruction
{
    public:
        l_default();
        int parse(string args, int line);
        string read();
        virtual ~l_default();

};

#endif // L_DEFAULT_H