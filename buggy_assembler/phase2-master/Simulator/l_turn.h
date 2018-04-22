/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   l_turn.h
 * Author: oana
 *
 * Created on March 2, 2018, 8:05 PM
 */

#ifndef L_TURN_H
#define L_TURN_H
#include "Structs.h"

class l_turn: public Instruction
{
    private:
        tleftright lr;
        tstate z;
    public:
        void execute(Bug b);
        void parse (string args);
};


#endif /* L_TURN_H */

