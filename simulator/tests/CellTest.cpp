/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newsimpletest.cpp
 * Author: mohit
 *
 * Created on March 4, 2018, 11:11 PM
 */

#include <stdlib.h>
#include "../headers/Cell.h"
#include "../headers/bug.h"
#include <gtest/gtest.h>
using namespace std;
/*
 * Simple C++ Test Suite
 */

TEST(DISABLED_CellTest, StaticGetters){
    Cell obstruct = Cell('#');
    Cell black_home = Cell('-');
    Cell red_home = Cell('+');
    EXPECT_TRUE(obstruct.get_obstructed());
    EXPECT_TRUE(black_home.is_black_home_area());
    EXPECT_TRUE(red_home.is_red_home_area());
}

TEST(DISABLED_CellTest, OccupantGetters){
    Bug* occupant = new Bug();
    Cell cell = Cell('.');
    try{
        cell.get_occupant();
    }
    catch(Exception e){
        EXPECT_STREQ(e.what(), "Occupant hasn't been set yet");
    }
    cell.set_occupant(occupant);
    Bug* occupantReceived = cell.get_occupant();
    EXPECT_TRUE(occupantReceived == occupant);
}

TEST(DISABLED_CellTest, FoodGetters){
    Cell cell = Cell('9');
    EXPECT_EQ(cell.get_food(), 9);
    cell = Cell('.');
    EXPECT_EQ(cell.get_food(), 0);
    cell.set_food(105);
    EXPECT_EQ(cell.get_food(), 105);
    try{
        cell.set_food(-102);
    }
    catch(Exception e){
        EXPECT_STREQ(e.what(), "Food can't be negative valued");
    }
}

