/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "./headers/bug.h"
#include <iostream>

using namespace std;

void Bug::bug_stats(){
    cout << "Bug stats: \n";
    cout << "Color:" << color.c << endl;
    cout << "ProgID:" << prog_id << endl;
    cout << "Dead:" << dead << endl;
    cout << "Resting:" << resting << endl;
    cout << "Position:" << pos.x << " " << pos.y << endl;
    cout << "Food:" << has_food << endl;
    cout << "State:" << state.st << endl;
    cout << "Direction: " << direction.d << endl;
}

//phase 4
void Bug::move(){
    int d = get_direction();
    aux::tposition p = get_position();
    try{
        switch(d){ //depending on the direction, move the bug by 1 unit forward. 
            case 0:
                p.x += 1;
                break;
            case 1:
                p.x += 1;
                p.y += 1;
                break;
            case 2:
                p.y += 1;
            case 3:
                if(p.x != 0){
                    p.x -= 1;
                }
                break;
            case 4:
                if(p.y != 0){
                    p.y -= 1;
                }
                break;
            case 5:
                p.x += 1;
                if(p.y != 0){
                    p.y -= 1;
                }
                break;
            default:
                throw "Invalid number for direction!\n";
                break;
        }
        set_position(p);
    }
    
    catch (char* e){
        cout << e;
    }
}

aux::tposition Bug::get_move_position(){
    int d = get_direction();
    aux::tposition p = get_position();
    try{
        switch(d){ //depending on the direction, move the bug by 1 unit forward. 
            case 0:
                p.x += 1;
                break;
            case 1:
                p.x += 1;
                p.y += 1;
                break;
            case 2:
                p.y += 1;
            case 3:
                if(p.x != 0){
                    p.x -= 1;
                }
                break;
            case 4:
                if(p.y != 0){
                    p.y -= 1;
                }
                break;
            case 5:
                p.x += 1;
                if(p.y != 0){
                    p.y -= 1;
                }
                break;
            default:
                throw "Invalid number for direction!\n";
                break;
        }
        return p;
    }
    
    catch (char* e){
        cout << e;
    }
};