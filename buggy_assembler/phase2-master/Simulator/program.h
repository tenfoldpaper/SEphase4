/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   program.h
 * Author: oana
 *
 * Created on March 2, 2018, 7:15 PM
 */

#ifndef PROGRAM_H
#define PROGRAM_H
#include "Bug.h"
#include "World.h"
#include "Cell.h"

class Program{
private :
    int id;
public:
    Program(string filename);
    void step(Bug b);
};

#endif /* PROGRAM_H */

