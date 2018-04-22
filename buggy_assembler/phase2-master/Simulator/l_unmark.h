/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   l_unmark.h
 * Author: oana
 *
 * Created on March 2, 2018, 7:48 PM
 */

#ifndef L_UNMARK_H
#define L_UNMARK_H
#include "Structs.h"

class l_unmark: public Instruction
{
private: 
    int m;
    tstate z;
public:
    void execute(Bug b);
    void parse(string args);
};

#endif /* L_UNMARK_H */

