/*
* Instruction.h
* Gisi Musa
*/

#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include <iostream.h>

class Instruction
{
    public:
        Instruction();
        virtual int parse(std::string args, int line) = 0;
        void error(std::string msg);
        virtual string read() = 0;
        virtual ~Instruction();

    private:
        int line;
        Labels l_list;
};

#endif // INSTRUCTION_H