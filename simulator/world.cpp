/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   world.cpp
 * Author: whitebox
 *
 * Created on March 3, 2018, 3:07 PM
 */

#include <cstdlib>
#include "./headers/bug.h"
#include "./headers/aux.h"
#include "./headers/world.h"
#include <string>
#include <iostream>
#include <fstream>
#include "./headers/Cell.h"
#include <algorithm>
#include "./headers/program.h"
#include <time.h> //for rand 

using namespace std;

/*
 * 
 */

bool even(int n){
    return (n % 2);
}

bool odd(int n){
    return !(n%2);
}

int World::load(string mapname){
    ifstream wf,pf;
    string line;
    aux::tcolor black;
    aux::tcolor red;
    black.c = 0;
    red.c = 1;
    int bbcount = 0;
    int rbcount = 0;
    wf.open(mapname, ios::in);
    if(wf.is_open()){
        wf >> width >> length;
    }
    else{
        error("No such file exists. Check again? \n");
        return 1;
    }
    cout << "Width: "<< width << endl;
    cout << "Length: " << length << endl;
    
    cell_container.resize(length);
    cout << "Mother vector resized \n" ;
            
    for(size_t i = 0; i < width; i++){
        cell_container[i].resize(width);
    }
    cout << "Child vectors resized \n";
    
    getline(wf, line);
    //cout << line;
    for (int l = 0; l < length; l++){
        getline(wf, line);
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
        for (int w = 0; w < width; w++){
            //cout << line[w];
            Cell *new_cell = new Cell(line[w]);
            cell_container[l][w] = new_cell;
            if(line[w] == '+'){
                //Bug new_bug = (new_cell->get_occupant());                
                Bug *new_bug = new Bug(red, rbcount, 0);
                new_bug->set_position(w, l);
                new_bug->set_has_food(false);
                redbugs.push_back(new_bug);
                new_cell->set_occupant(redbugs[rbcount]);
                rbcount++;
                //cout << "Red bug home base found; Creating a bug...\n";
            }
            if(line[w] == '-'){
                //Bug new_bug = (new_cell->get_occupant());
                Bug *new_bug = new Bug(black, bbcount, 0);
                new_bug->set_position(w, l);
                new_bug->set_has_food(false);
                blackbugs.push_back(new_bug);
                new_cell->set_occupant(blackbugs[bbcount]);
                bbcount++;
                //cout << "Black bug home base found; Creating a bug...\n";
            }
            
            //cout << "Cell assigned successfully" << endl;
        }
        //cout << endl;
        
    }
    cout << "World initialization complete. \n";
    return 0;
}
//phase 4
aux::tcolor World::winner(){
    
    int black_score = black_food();
    int red_score = red_food();
    cout << "Black food: " << black_score << endl;
    cout << "Red food: " << red_score << endl;
    int winnerInt;
    if(black_score == red_score){
        winnerInt = 999;
    }
    else{
        winnerInt = (int)(black_score < red_score);
    }
    aux::tcolor winningTeam;
    winningTeam.c = winnerInt;
    return winningTeam;
}

int World::cell_test(){
    for(int l = 0; l < length; l++){
        for(int w = 0; w < width; w++){
            if(cell_container[l][w]){
                //cout << "Cell " << l << " " << w << " exists. \n" << endl;
            }
            else{
                return 1;
            }
        }
    }
    return 0;
}
//********phase 4//

aux::tposition World::adjacent(aux::tdirection dir, aux::tposition pos){
    int d = dir.d;
    aux::tposition res;
    switch(d){
        case 0:
            res.x = pos.x + 1;
            res.y = pos.y;
            break;
        case 1:
            if(even(pos.y)){
                res.x = pos.x;
                res.y = pos.y+1;
            }
            else{
                res.x = pos.x+1;
                res.y = pos.y+1;
            }
            break;
        case 2:
            if(even(pos.y)){
                res.x = pos.x-1;
                res.y = pos.y+1;
            }
            else{
                res.x = pos.x;
                res.y = pos.y+1;
            }
            break;
        case 3:
            res.x = pos.x-1;
            res.y = pos.y;
            break;
        case 4:
            if(even(pos.y)){
                res.x = pos.x-1;
                res.y = pos.y-1;
            }
            else{
                res.x = pos.x;
                res.y = pos.y-1;
            }
            break;
        case 5:
            if(even(pos.y)){
                res.x = pos.x;
                res.y = pos.y-1;
            }
            else{
                res.x = pos.x+1;
                res.y = pos.y-1;
            }
            break;
        default:
            cout << "Error!" << endl;
            res.x = -1;
            res.y = -1;
            throw("Invalid direction integer!\n");
            ///raise exception here;
            break;
    }
    return res;
    
}

//Implemented Oana's 
aux::tcolor World::other_color(aux::tcolor c){
    aux::tcolor res;
    res.c = 1 - c.c;
    
    return res;
}


int World::red_food(){
    int count = 0;
    for(int i = 0; i<World::red_count(); i++){
        if(redbugs[i]->get_has_food()){
            count++;
        }
    }
    //phase 4
    for(int j = 0; j<length; j++){
        for (int k = 0; k<length; k++){
            if(cell_container[j][k]->is_red_home_area()){
                count += cell_container[j][k]->get_food();
            }
        }
    }
    
    return count;
}

int World::black_food(){
    int count = 0;
    for(int i = 0; i<World::black_count(); i++){
        if(blackbugs[i]->get_has_food()){
            count++;
        }
    }
    //phase 4
    for(int j = 0; j<length; j++){
        for (int k = 0; k<length; k++){
            if(cell_container[j][k]->is_black_home_area()){
                count += cell_container[j][k]->get_food();
            }
        }
    }
    
    return count;
}

int World::red_count(){
    return redbugs.size();
}
int World::black_count(){
    return blackbugs.size();
}

void World::error(string msg){
    cout << msg << endl;
}

void World::log(string msg){
    ofstream logfile;
    logfile.open("log.txt", ios::out);
    if(logfile.is_open()){
        logfile << msg << endl;
        cout << "successfully logged \n"; 
    }
    logfile.close();
    
}

void World::print_grid(){
    for(int i = 0; i < cell_container.size(); i++){
        for(int j = 0; j < cell_container[0].size(); j++){
            cout << cell_container[i][j]->get_char() << " ";
        }
        cout << endl;
    }
}

bool World::place_at(aux::tposition p, Bug* b){
    if(cell_container[p.y][p.x]->occupied()){
        throw ("The cell is already occupied!");
    }
    else{
        b->set_position(p.x, p.y);
    }
}

int World::food_at(aux::tposition p){
    return get_cell(p)->get_food();
};
bool World::set_food_at(aux::tposition p, int f){ //now additive;
    if(get_cell(p)->get_obstructed() ){
        return false;
    }
    else{
        get_cell(p)->add_more_food(f);
    }
};
    
bool World::base_at(aux::tposition p, aux::tcolor c){
    if(c.c = 0){
        return get_cell(p)->is_black_home_area();
    }
    else return get_cell(p)->is_red_home_area();
};
bool World::other_base_at(aux::tposition p, aux::tcolor c){
    return !base_at(p, c);
};
    

//phase 4
bool World::cell_matches(aux::tposition p, aux::tcondition cond, aux::tcolor c){
    Cell* cell = get_cell(p);
    aux::tmark t_mark;
    
    //Check for team-irrelevant conditions first 
    if(cell->get_obstructed()){
        return cond.cond == 6;
    }
    
    if(cond.cond == 5){
        return cell->get_food();
    }
    
    if(!c.c){ //the bug checking is black
        switch(cond.cond){
            case 1: //friend
                if(cell->occupied()){
                    return cell->get_occupant()->get_color().c == c.c;
                }
                break;
            case 2: //foe
                if(cell->occupied()){
                    return cell->get_occupant()->get_color().c != c.c;
                }
                break;
            case 3: //friend with food
                if(cell->occupied()){
                    return (cell->get_occupant()->get_color().c == c.c &&
                            cell->get_occupant()->get_has_food());
                }
                break;
            case 4: //foe with food
                if(cell->occupied()){
                    return (cell->get_occupant()->get_color().c != c.c &&
                            cell->get_occupant()->get_has_food());
                }
                break;
            case 7: //marker
                for(int marks = 0; marks < 6; marks++){
                    t_mark.m = marks;
                    if(cell->mark.check_marker(t_mark, c)){
                        return true;
                    }
                }
                break;
            case 8: //foe marker
                return cell->mark.check_other_marker(c);
                break;
            case 9: //home
                return cell->is_black_home_area();
                break;
            case 10: //foe home
                return cell->is_red_home_area();
                break;
            default:
                return false;
        }
        
    }
    else{ //the bug checking is red
        switch(cond.cond){
            case 1: //friend
                if(cell->occupied()){
                    return cell->get_occupant()->get_color().c == c.c;
                }
                break;
            case 2: //foe
                if(cell->occupied()){
                    return cell->get_occupant()->get_color().c != c.c;
                }
                break;
            case 3: //friend with food
                if(cell->occupied()){
                    return (cell->get_occupant()->get_color().c == c.c &&
                            cell->get_occupant()->get_has_food());
                }
                break;
            case 4: //foe with food
                if(cell->occupied()){
                    return (cell->get_occupant()->get_color().c != c.c &&
                            cell->get_occupant()->get_has_food());
                }
                break;
            case 7: //marker
                for(int marks = 0; marks < 6; marks++){
                    t_mark.m = marks;
                    if(cell->mark.check_marker(t_mark, c)){
                        return true;
                    }
                }
                break;
            case 8: //foe marker
                return cell->mark.check_other_marker(c);
                break;
            case 10: //foe home
                return cell->is_black_home_area();
                break;
            case 9: //home
                return cell->is_red_home_area();
                break;
            default:
                return false;
        }
    }
    
};
//***********************phase 4//    

//Martial arts
int World::adjacent_other_bugs(aux::tposition p, aux::tcolor c){
    aux::tdirection d;
    int count = 0;
    for(int i = 0; i < 6; i++){
        d.d = i;
        aux::tposition adjp = adjacent(d, p);
        if(get_cell(adjp)->occupied()){
            if(get_cell(adjp)->get_occupant()->get_color().c == c.c){
                count++;
            }
        }
    }
    return count;
};

void World::kill_if_surrounded(aux::tposition p){
    if(p.x < 1 || p.y < 1 || p.x > width - 2 || p.y > length - 2){
        return;
    }
    if(get_cell(p)->occupied()){
        Bug* b = get_cell(p)->get_occupant();
        aux::tcolor oc = other_color(b->get_color());
        if(adjacent_other_bugs(p, oc) > 4){
            cout <<"This bug is surrounded! Alas, I must commit seppuku...\n";
            int i = 0;
            if (b->get_has_food()){ //drop an extra food if bug had one
                i = 1;
            }
            
            //set the cell up accordingly 
            set_food_at(p, (5 + i));
            cout << "Coordinates of the dead bug: \n" << "x: " << p.x << " y: " << p.y << endl;
            get_cell(p)->get_occupant()->kill();
            get_cell(p)->set_occupant(NULL);
            get_cell(p)->set_occupancy(false);
        }
        else{
           //cout <<"I shall live to see another day!\n";
        }
    }
};

void World::check_for_surrounded_bugs(aux::tposition p){
    kill_if_surrounded(p);
    aux::tdirection dir;
    for(int d = 0; d < 6; d++){
        dir.d = d;
        kill_if_surrounded(adjacent(dir, p));
    }
};

//phase 4
void World::check_for_surrounded_bugs_mapwide(){
    for (int i = 0; i < blackbugs.size(); i++){
        check_for_surrounded_bugs(blackbugs[i]->get_position());
    }
    for (int i = 0; i < redbugs.size(); i++){
        check_for_surrounded_bugs(redbugs[i]->get_position());
    }
}
aux::tposition get_ahead_position(aux::tposition p, int d){
    aux::tposition res;
    res = p;
    switch(d){
        case 0:
            break;
        case 1:
            res.x += 1;
            break;
        case 2:
            res.x += 1;
            res.y -= 1;
            break;
        case 3:
            res.x += 1;
            res.y += 1;
            break;
        default:
            throw "Invalid sensedir value.\n";
            break;
            
    }
    return res;
};

int cond_to_int(std::string cond){
    if(cond == "friend"){
        return 1;
    }
    if(cond == "foe"){
        return 2;
    }
    if(cond == "friendwithfood"){
        return 3;
    }
    if(cond == "foewithfood"){
        return 4;
    }
    if(cond == "food"){
        return 5;
    }
    if(cond == "rock"){
        return 6;
    }
    if(cond == "marker"){
        return 7;
    }
    if(cond == "foemarker"){
        return 8;
    }
    if(cond == "home"){
        return 9;
    }
    if(cond == "foehome"){
        return 10;
    }
    return -1;
}

bool World::sense(Bug* b, aux::tsensedir d, std::string cond){
    aux::tposition sense_p = get_ahead_position(b->get_position(), d.s);
    int condint = cond_to_int(cond);
    aux::tcondition tc(condint);
    return cell_matches(sense_p, tc, b->get_color());
    };
    
void World::mark(Bug* b, int i){
    aux::tcolor c = b->get_color();
    aux::tposition p = b->get_position();
    aux::tmark m(i);
    get_cell(p)->get_mark().set_marker(m, c);
};
void World::unmark(Bug* b, int i){
    aux::tcolor c = b->get_color();
    aux::tposition p = b->get_position();
    aux::tmark m(i);
    get_cell(p)->mark.clear_marker(m, c);
};

bool World::pickup(Bug* b){
    if(!b->get_has_food() && get_cell(b->get_position())->get_food()){ //if the bug doesn't have any food
        b->set_has_food(true); //pick up the food
        get_cell(b->get_position())->subtr_food(); //and minus 1 from the cell
        return true;
    }
    else{
        return false;
    }
};
bool World::drop(Bug* b){ //bug must have food
    if(b->get_has_food()){
        b->set_has_food(false);
        aux::tposition p = b->get_position();
        get_cell(p)->add_food();
        return true;
    }
    else{
        cout << "no food to drop!\n"; //This should never happen if the brain is well-configured
        return false;
    }
};

void World::turn(Bug* b, int lr){
    int curr_dir = b->get_direction();
    if(lr == 0){ //left 
        if (curr_dir== 0){
            b->set_direction(5);
        }
        else{
            b->set_direction(curr_dir-1);
        }
    }
    else{ //turn right
        if (curr_dir == 5){
            b->set_direction(0);
        }
        else{
            b->set_direction(curr_dir+1);
        }
    }
};

bool World::move(Bug* b){ //move forward in the current direction by 1 unit
    if(!get_cell(b->get_move_position())->get_obstructed()){
        b->move();
        return true;
    }
    else{
        return false;
    }
};

//random function

//flip is broken 
bool World::flip(Bug* b, int n){
    int x = rand()%n;
    //cout << " "<< x << " ";
    return (x == 0);
};

bool World::direction(Bug* b, int n){
    return (b->get_direction() == n);
};
