/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include "../headers/inst/instruction.h"
#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <vector>
#include "../headers/program.h"

using namespace std;

TEST(ProgramTest, initandgetter){
    Program p(1, "final.bug", "final.bug");
    
    cout << p.get_blackinst().size() << p.get_redinst().size() << endl;
    for(int i = 0; i < p.get_blackinst().size(); i++){
        cout << p.get_blackinst()[i]->get_iName() << endl;
    }
    
    for(int i = 0; i < p.get_redinst().size(); i++){
        cout << p.get_redinst()[i]->get_iName() << endl;
    }
}
