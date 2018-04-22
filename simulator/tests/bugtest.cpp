/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <gtest/gtest.h>
#include "../headers/bug.h"

TEST(DISABLED_BugTest, testConst){
    Bug buggy;
    buggy.set_position(1,1);
    buggy.set_direction(1);
    EXPECT_EQ(1, buggy.get_direction());
    EXPECT_EQ(1, buggy.get_position().x);
    EXPECT_EQ(1, buggy.get_position().y);
    buggy.kill();
    EXPECT_EQ(true, buggy.is_dead());
    buggy.bug_stats();
}
