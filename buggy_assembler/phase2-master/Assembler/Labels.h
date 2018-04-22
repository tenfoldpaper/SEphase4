/*
* Labels.h
* Gisi Musa
*/

#ifndef LABELS_H
#define LABELS_H
#include "allHeaders.h"
#include <iostream>

class Labels
{
    public:
        Labels();
        int line_of(std::string label);
        void add_label(std::string label, int line);
        void add_goto(std::string label, int line);
        int resolve_goto(int line);
        void error(std::string msg);
        virtual ~Labels();
};

#endif // LABELS_H