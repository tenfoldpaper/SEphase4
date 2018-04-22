/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <gtest/gtest.h>
#include "../headers/world.h"

TEST(DISABLED_MATest, testKIS){
    World w;
    w.load("map.txt");
    Bug* b = w.get_blackbugs()[0];
    w.kill_if_surrounded(b->get_position());
    EXPECT_EQ(false, w.get_blackbugs()[0]->is_dead());
}

TEST(DISABLED_MATest, testKIS2){
    World w;
    w.load("./tests/surekill.txt");
    cout<<w.get_blackbugs().size() << endl;
    cout<<w.get_redbugs().size() << endl;
    Bug* b = w.get_redbugs()[0];
    aux::tposition p;
    p.y = 5;
    p.x = 3;
    //w.kill_if_surrounded(b->get_position());
    //EXPECT_EQ(true, w.get_cell(p)->occupied());
    //w.check_for_surrounded_bugs(p);
    
    for(int i = 0; i < w.get_length(); i++){
        for(int j = 0; j < w.get_width(); j++){
            p.x = j;
            p.y = i;
            w.check_for_surrounded_bugs(p);
        }
    }
    
}