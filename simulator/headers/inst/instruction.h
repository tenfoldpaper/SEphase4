/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   instruction.h
 * Author: Jin
 *
 * Created on April 22, 2018, 6:25 PM
 */

#ifndef INSTRUCTION_H
#define INSTRUCTION_H
//phase 4
#include <string>
#include "../aux.h"
#include <vector>
class instruction{
private:
    std::string iName;
    int iID; //instruction ID, as determined by the parser
    aux::tstate x;
    aux::tstate y;
    aux::tdirection direction;
    std::string cond;
    int marker = -1;
    int sensedir = -1;
    int lr = -1; //left = 0 or right = 1
    int n = -1;
    
public:
    instruction();
    instruction(std::vector<string>);
    ~instruction();
    
    void parse(std::vector<string>);
    
    std::string get_iName();
    void set_iName(std::string);
    
    aux::tstate get_xState();
    aux::tstate get_yState();
    void set_xState(aux::tstate newx);
    void set_yState(aux::tstate newy);
    
    std::string get_cond();
    void set_cond(std::string newc);
    
    int get_lr();
    void set_lr(int newlr);
    
    int get_iID();
    void set_iID(int);
    
    int get_sensedir();
    void set_sensedir(int);
    
    int get_marker();
    void set_marker(int);
    
    int get_n();
    void set_n(int);
    
    aux::tdirection get_direction();
    void set_direction(int);
    
    void print_inst();
};


#endif /* INSTRUCTION_H */

