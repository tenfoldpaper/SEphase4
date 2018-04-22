/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//phase 4
#include <stdlib.h>
#include "../headers/inst/instruction.h"
#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <vector>
TEST(InstrTest, Parser){
    std::vector<string> c;
    c.push_back("flip");
    c.push_back("3");
    c.push_back("4");
    c.push_back("5");
    instruction inst(c);
    
}