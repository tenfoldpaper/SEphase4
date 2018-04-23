/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cell.h
 * Author: mohit
 *
 * Created on February 25, 2018, 10:24 PM
 */

#ifndef CELL_H
#define CELL_H
#include "bug.h"
#include "Marker.h"
#include "bug.h"
#include "aux.h"

#ifdef __cplusplus
extern "C" {
#endif
    class Cell{
    private:
        Bug* occupant;
        bool obstructed; //Blocked cell
        int food;
        bool home_black_bug;
        bool home_red_bug;
        bool occupant_set;
        char c;
    public:
        Marker mark;
        Marker get_mark(){
            return mark;
        }
        Cell(char symb);
        Bug* get_occupant();
        void set_occupant(Bug* new_occupant);
        void set_occupancy(bool);
        int get_food(); //return number of food available
        void set_food(int new_food);
        void add_more_food(int);
        void add_food(){
            food++;
        }
        void subtr_food(){
            if(food){
                food--;
            }
        }
        bool get_obstructed();
        bool is_black_home_area();
        bool is_red_home_area();
        char get_char(){
            return c;
        }
        bool occupied();
    };



#ifdef __cplusplus
}
#endif

#endif /* CELL_H */

