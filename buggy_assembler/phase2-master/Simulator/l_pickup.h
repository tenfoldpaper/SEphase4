/*  
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   l_pickup.h
 * Author: oana
 *
 * Created on March 2, 2018, 7:31 PM
 */

#ifndef L_PICKUP_H
#define L_PICKUP_H
#include "Structs.h"

class l_pickup: public Instruction
{
private:
    tstate x;
    tstate y;
public:
    void execute(Bug b);
    void parse(string args);
};


#endif /* L_PICKUP_H */

