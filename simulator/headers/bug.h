/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bug.h
 * Author: whitebox
 *
 * Created on February 25, 2018, 10:39 PM
 */

#ifndef BUG_H
#define BUG_H

using namespace std;

#include "aux.h"
#include <iostream>
#include <string>
#include "exception.h"

class Bug{
public:
    /*Getters and setters for bug variables*/
    Bug(){
        color.c = 0;
        prog_id = 999;
        resting = 0;
        dead = false;
        direction.d = 0;
        has_food = false;
        
    };
    
    ~Bug(){};
    
    Bug(aux::tcolor c, int new_pid, int new_resting){
        if(c.c > 1 || c.c < 0){
            throw Exception("Color number must be 0 or 1.\n");
        }
        color = c;
        prog_id = new_pid;
        resting = new_resting;
        remaining_rest=0;
//        cout << "Bug has been init'd with following parameters: \n" 
//                << "Color:" << color.c 
//                << "\n ID: "<< prog_id 
//                << "\n Resting: "<< resting 
//                << "\n Remaining rest: "<< remaining_rest;
                
        
    }
    
    //Getter functions, as per bug.pdf
    int get_state(){
        return state.st;
    }
    void set_state(aux::tstate s){
        state = s;
    }
    void set_state(int s){
        state.st = s;
    }
    
    int get_direction(){
        return direction.d;
    }
    void set_direction(int dir){
        direction.d = dir;
    }
    
    bool get_has_food(){
        return has_food;
    }
    void set_has_food(bool f){
        if(has_food == true && f == true){
            throw Exception("Bug already has food! \n");
        }
        if(has_food == false && f == true){
            cout << "Grabbing food!\n";
        }
        has_food = f;
    }
    
    aux::tcolor get_color(){ //this returns either a 0 or 1, i.e. black or red. 
        return color; 
    }
    void set_color(int cl){
        if(cl < 0 || cl > 1){
            throw Exception("Color must be 1 or 0.\n");
        }
        color.c = cl;
    }
    
    int get_prog_id(){
        return prog_id;
    }
    
    void set_position(int x, int y){
        pos.x = x;
        pos.y = y;
    }
    
    void set_position(aux::tposition p){
        pos = p;
    }
    
    aux::tposition get_position(){
        return pos;
    }
    
    void start_resting(){//fixed
        if(remaining_rest==resting)
            throw "The bug was already resting\n";
        remaining_rest=resting; 
    }
    
    bool rested(){
        if(remaining_rest>0)//fixed
        {
            remaining_rest--;
            return 0;
        }
        else
        {
            return 1;
        }
    }
    
    bool is_dead(){
        return dead;
    }
    
    void kill(){
        if(dead == true){
            throw Exception("Bug is already dead!\n");
        }
        dead = true;
//        cout << "Killed the bug!" << endl;
    }
    
    inline bool operator==(const Bug& b){ 
        if((b.color.c == color.c) && (b.prog_id == prog_id)){
            return true;
        }
        return false;                
    }
    
    void move();
    
    void set_resting(int r){
        resting = r;
    }
    int get_resting(){
        return resting;
    }
    
    aux::tposition get_move_position();
    
    void bug_stats();
//b stands for bug; so, bug state, bug color, etc.     
private:
    aux::tstate state;
    aux::tcolor color;
    aux::tdirection direction;
    int resting;
    bool has_food = false;
    int prog_id;
    aux::tposition pos;
    bool dead = false;
    int remaining_rest = 0;
    
};


#endif /* BUG_H */

