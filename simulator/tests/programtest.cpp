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
    Program p(1, "map2.txt", "final.bug", "final.bug");
    
    World w = p.get_world();
    p.run_game(1000);
    
    /*
    int yes = 0;
    int no = 0;
    for(int i = 0; i < 1000; i++){
        if(w.flip(w.get_blackbugs()[1], 3)){
            yes++;
        }
        else no++;
       
    }
    cout << yes << endl << no << endl;
     * */
}

