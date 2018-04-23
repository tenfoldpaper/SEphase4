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
    Program p(1, "map.txt", "final.bug", "final.bug");
    
    cout << p.get_blackinst().size() << p.get_redinst().size() << endl;
    for(int i = 0; i < p.get_blackinst().size(); i++){
        p.get_blackinst()[i]->print_inst();
    }
    
    for(int i = 0; i < p.get_redinst().size(); i++){
        p.get_redinst()[i]->print_inst();
    }
    
    World w = p.get_world();
      p.run_game(1000);
    
}

