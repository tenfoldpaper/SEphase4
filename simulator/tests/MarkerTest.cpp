/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MarkerTest.cpp
 * Author: mohit
 *
 * Created on March 5, 2018, 5:41 PM
 */

#include <stdlib.h>
#include <gtest/gtest.h>
#include "../headers/Marker.h"
#include "../headers/exception.h"
/*
 * Simple C++ Test Suite
 */

TEST(DISABLED_MarkerTest, ProperInput){
    Marker marker = Marker();
    aux::tcolor color;
    aux::tmark mark;
    color.c = 1;
    mark.m = 3;
    marker.set_marker(mark, color);
    EXPECT_TRUE(marker.check_marker(mark, color));
    EXPECT_TRUE(marker.check_other_marker(color));
    marker.clear_marker(mark, color);
    EXPECT_FALSE(marker.check_marker(mark, color));
    EXPECT_FALSE(marker.check_other_marker(color));
    color.c = 0;
    EXPECT_FALSE(marker.check_other_marker(color));
    color.c = 0;
    mark.m = 1;
    EXPECT_FALSE(marker.check_marker(mark, color));
    EXPECT_FALSE(marker.check_other_marker(color));   
}

TEST(DISABLED_MarkerTest, ErroneousInput){
    Marker marker = Marker();
    aux::tcolor color;
    aux::tmark mark;
    color.c = 6;
    mark.m = 10;
    try{
        marker.set_marker(mark, color);
    }
    catch(Exception e){
        EXPECT_STREQ(e.what(), "Mark must be number between 0 and 5\n"); //because mark error check is before color
    }
    try{
        marker.clear_marker(mark, color);
    }
    catch(Exception e){
        EXPECT_STREQ(e.what(), "Mark must be number between 0 and 5\n"); //because mark error check is before color
    }
    try{
        marker.check_other_marker(color);
    }
    catch(Exception e){
        EXPECT_STREQ(e.what(), "Color must be either 0 or 1\n"); 
    }
    try{
        marker.check_marker(mark, color);
    }
    catch(Exception e){
        EXPECT_STREQ(e.what(), "Mark must be number between 0 and 5\n"); //because mark error check is before color
    }
}

TEST(DISABLED_MarkerTest, MixedInput){
    Marker marker = Marker();
    aux::tcolor color;
    aux::tmark mark;
    color.c = 1;
    mark.m = 6;
    try{
        marker.set_marker(mark, color);
    }
    catch(Exception e){
        EXPECT_STREQ(e.what(), "Mark must be number between 0 and 5\n");
    }
    color.c = 5;
    mark.m = 1;
    try{
        marker.check_marker(mark, color);
    }
    catch(Exception e){
        EXPECT_STREQ(e.what(), "Color must be either 0 or 1\n");
    }
}