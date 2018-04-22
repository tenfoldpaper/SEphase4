/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   l_drop.h
 * Author: oana
 *
 * Created on March 2, 2018, 8:07 PM
 */

#ifndef L_DROP_H
#define L_DROP_H
#include "Structs.h"

class l_drop: public Instruction 
{
    private:
        tstate z;
    public:
        void execute(Bug b);
        void parse(string args);
};


#endif /* L_DROP_H */

