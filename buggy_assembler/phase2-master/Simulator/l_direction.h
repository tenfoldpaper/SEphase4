/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   l_direction.h
 * Author: oana
 *
 * Created on March 2, 2018, 7:40 PM
 */

#ifndef L_DIRECTION_H
#define L_DIRECTION_H
#include "Structs.h"

class l_direction:public Instruction
{
private:
    tdir d;
    tstate x;
    tstate y;
public:
    void execute(Bug b);
    void parse(string args);    
};


#endif /* L_DIRECTION_H */

