/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   world.h
 * Author: whitebox
 *
 * Created on March 3, 2018, 3:07 PM
 */

#ifndef WORLD_H
#define WORLD_H
#include "bug.h"
#include "aux.h"
#include <vector>
#include "Cell.h"
#define MAX_SIZE 500;

class World{
private:
    int width;
    int length;
    std::vector<Bug*> redbugs;
    std::vector<Bug*> blackbugs;
    std::vector< std::vector<Cell*> > cell_container;
    //Cell::Cell *cells[];
    
    
public:
    World(){
        width = 0;
        length = 0;
    };
    ~World(){};
    int load(string);
    void execute_cycle();
    //cell::Cell get_cell(aux::tposition);
    aux::tposition adjacent(aux::tdirection, aux::tposition);
    aux::tcolor other_color(aux::tcolor);
    aux::tcolor winner(); //phase 4
    int red_food();
    int black_food();
    int red_count();
    int black_count();
    void error(string);
    void log(string);
    void print_grid();
    int cell_test();
    int get_length(){
        return length;
    };
    Cell* get_cell(aux::tposition p){
        return cell_container[p.y][p.x];
    }
    int get_width(){
        return width;
    };
    vector<Bug*> get_redbugs(){
        return redbugs;
    }
    vector<Bug*> get_blackbugs(){
        return blackbugs;
    }
    std::vector< std::vector<Cell*> > get_cellcont(){
        return cell_container;
    }
    
    Bug* bug_at(aux::tposition p){
        return cell_container[p.y][p.x]->get_occupant();
    }
    
    bool cell_matches(aux::tposition, aux::tcondition, aux::tcolor);
    
    bool place_at(aux::tposition, Bug*);
    int food_at(aux::tposition);
    bool set_food_at(aux::tposition, int);
    
    bool base_at(aux::tposition, aux::tcolor);
    bool other_base_at(aux::tposition, aux::tcolor);
    
    //Martial arts
    int adjacent_other_bugs(aux::tposition, aux::tcolor);
    void kill_if_surrounded(aux::tposition);
    void check_for_surrounded_bugs(aux::tposition);
    void check_for_surrounded_bugs_mapwide();
    
    //phase 4
    //Brain functions
    bool sense(Bug*, aux::tsensedir, std::string);
    void mark(Bug*, int);
    void unmark(Bug*, int);
    bool pickup(Bug*);
    bool drop(Bug*);
    void turn(Bug*, int);
    bool move(Bug*);
    bool flip(Bug*, int);
    bool direction(Bug*, int);
    
};



#endif /* WORLD_H */

