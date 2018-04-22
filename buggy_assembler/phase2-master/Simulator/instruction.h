/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   instruction.h
 * Author: oana
 *
 * Created on March 2, 2018, 7:19 PM
 */

#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include "Structs.h"
#include <string>
class Instruction
{
private:
    World w;
public:
    virtual void execute(Bug b);
    virtual void parse(string args);
};

#endif /* INSTRUCTION_H */

