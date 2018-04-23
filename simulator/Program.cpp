#include "./headers/program.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cmath>
#include <time.h>

using namespace std;

//phase 4
vector<std::string> split(string s, char delim){
    stringstream ss(s);
    string item;
    vector<std::string> elems;
    while(std::getline(ss, item, delim)){
        if(item!=""){
            elems.push_back(item);
        }
    }
    return elems;
}


Program::Program(int prog_id, string mapfile, string black_bug, string red_bug) //.bug and .map file input here 
{
    srand((unsigned)time(0));
    id = prog_id;
    w.load(mapfile);
    ifstream black_f(black_bug, std::ifstream::in);
    
    ifstream red_f(red_bug, std::ifstream::in);
    
    if(!black_f.good() || !red_f.good())
    {
        cout << black_f.good();
        throw "Unable to open the assembly language program file\n";
    }
    cout << "bug files opened\n";
    string c;
    
    while(getline(black_f, c)){
        vector<string> temp = split(c, ' ');
        instruction* i = new instruction(temp);
        black_inst.push_back(i);
    }
    
    while(getline(red_f, c)){
        vector<string> temp = split(c, ' ');
        instruction* i = new instruction(temp);
        red_inst.push_back(i);
    }
    
    cout << "Done initialising" << endl;
    
    
}

void Program::step(Bug* b){
    int sleep_cycles = 14;
    vector<instruction*> brain;
    if (b->is_dead()){
        //cout << "Bug " << b->get_prog_id() << " of team " << b->get_color().c << " is dead. \n";
        return;
    }
    else{
        aux::tposition pos = b->get_position();
        int dir = b->get_direction();
        aux::tcolor color = b->get_color();
        if(color.c == 0){
            brain = black_inst;
        }
        else{
            brain = red_inst;
        }
        int resting = b->get_resting();
        int curr_state = b->get_state();
        int s;
        if(resting > 0){
            //cout << "##########Resting: " << resting << endl;
            //cout << "I need to rest. "<< endl;
            b->set_resting(resting-1);
        }
        else{
            s = brain[curr_state]->get_iID();
            switch(s){
                //sense
                case 542:
                    //cout << "I sense a great disturbance in the force.\n";
                    if(w.sense(b, brain[curr_state]->get_sensedir(), brain[curr_state]->get_cond())){
                        b->set_state(brain[curr_state]->get_xState());
                    }
                    else{
                        b->set_state(brain[curr_state]->get_yState());
                    }
                    break;
                    
                //mark
                case 427:
                    //cout << "Nobody expects the Bug Inquisition. \n";
                    w.mark(b, brain[curr_state]->get_marker());
                    b->set_state(brain[curr_state]->get_xState());
                    break;
                    
                //unmark
                case 654:
                    //cout << "Clean up!\n";
                    w.unmark(b, brain[curr_state]->get_marker());
                    b->set_state(brain[curr_state]->get_xState());
                    break;
                    
                //pickup
                case 652:
                    //cout << "Ooh, a piece of candy.\n";
                    if(w.pickup(b)){
                        b->set_state(brain[curr_state]->get_xState());
                    }
                    else{
                        b->set_state(brain[curr_state]->get_yState());
                    }
                    break;
                    
                //drop
                case 437:
                    //cout << "Medivac drops\n";
                    if(w.drop(b)){
                        b->set_state(brain[curr_state]->get_xState());
                    }
                    else{
                        b->set_state(brain[curr_state]->get_yState());
                    }
                    break;
                    
                //turn
                case 457:
                    //cout << "Gotta turn hard!\n";
                    w.turn(b, brain[curr_state]->get_lr());
                    b->set_state(brain[curr_state]->get_xState());
                    break;
                    
                //move
                case 439:
                    //cout << "Go go go! \n";
                    if(w.move(b)){
                        b->set_state(brain[curr_state]->get_xState());
                        b->set_resting(sleep_cycles);
                    }
                    else{
                        b->set_state(brain[curr_state]->get_yState());
                    }
                    break;
                    
                //flip
                case 428:
                    //cout << "Oh flip. \n";
                    if(w.flip(b, brain[curr_state]->get_n())){
                        b->set_state(brain[curr_state]->get_xState());
                    }
                    else{
                        b->set_state(brain[curr_state]->get_yState());
                    };
                    break;
                    
                //direction
                case 961:
                    //cout << "Right way is no way.\n";
                    if(w.direction(b, brain[curr_state]->get_direction().d)){
                        b->set_state(brain[curr_state]->get_xState());
                    }
                    else{
                        b->set_state(brain[curr_state]->get_yState());
                    };
                    break;
            }
        }
    }
    
    return;
}

void Program::run_game(int n){
    int i = 0;
    int b = 0;
    int r = 0;
    int black_count = w.black_count();
    int red_count = w.red_count();
    
    for(i; i < n; i++){
        //cout << "Round " << i << ". FIGHT!\n";
        for(b; b < black_count; b++){
            step(w.get_blackbugs()[b]);
        }
        for(r; r < red_count; r++){
            step(w.get_redbugs()[r]);
        }
        b = 0;
        r = 0;
        w.check_for_surrounded_bugs_mapwide();
    }
    int winner = w.winner().c;
    if(winner == 1){
        cout << "Red wins!" << endl;
    }
    else if(winner == 0){
        cout << "Black wins!" << endl;
    }
    else{
        cout << "It's a draw!" << endl;
    }
}

World Program::get_world(){
    return w;
}