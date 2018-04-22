/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   l_sense.h
 * Author: oana
 *
 * Created on March 2, 2018, 7:21 PM
 */

#ifndef L_SENSE_H
#define L_SENSE_H
#include "Structs.h"

class l_sense: public Instruction
{
private:
    tsensedir dir;
    tstate x;
    tstate y;
    tcondition condition;
public:
    void execute(Bug b);
    void parse(string args);
};

#endif /* L_SENSE_H */

