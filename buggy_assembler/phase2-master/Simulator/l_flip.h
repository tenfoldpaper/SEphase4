/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   l_flip.h
 * Author: oana
 *
 * Created on March 2, 2018, 7:23 PM
 */

#ifndef L_FLIP_H
#define L_FLIP_H
#include "Structs.h"

class l_flip: public Instruction
{
private:
    int p;
    tstate x;
    tstate y;
    int seed;;
public:
    void execute(Bug b);
    void parse(string args);
    int randomint();
};

#endif /* L_FLIP_H */

