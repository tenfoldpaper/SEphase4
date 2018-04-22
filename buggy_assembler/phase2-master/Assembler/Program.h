/*
* Program.h
* Gisi Musa
*/

#ifndef PROGRAM_H
#define PROGRAM_H
#include "iostream"

class Program
{
    public:
        Program(std::string filename);
        void error(std::string msg);
        void  process();
        void exiport();
        virtual ~Program();

    private:
        int line = 0;
};

#endif // PROGRAM_H