/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "./headers/inst/instruction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

//phase 4
int wordtoint(string word){
    int res = 0;
    if(word == "flip"){
        res++;
    }
    for (int i = 0; i < word.length(); i++){
       
        res += (int)word[i];
    }
    return res;
}

instruction::instruction(){
    x.st = -1;
    y.st = -1;
    marker = -1;
    cond = "";
    lr = -1;
    iName = "";
}

instruction::instruction(vector<string> vec){
    instruction::parse(vec);
}

instruction::~instruction(){};

string instruction::get_iName(){
        return iName;
}

void instruction::set_iName(std::string nname){
        iName = nname;
        
}

int sensedir_to_int(std::string sensedir){
    if(sensedir=="here"){
        return 0;
    }
    if(sensedir=="ahead"){
        return 1;
    }
    if(sensedir=="leftahead"){
        return 2;
    }
    if(sensedir=="rightahead"){
        return 3;
    }
    else{
        return -1;
    }
}

void instruction::parse(std::vector<string> input_line){
    string keyword = input_line[0]; //we know all lines start with a command word
    iName = keyword;
    int keyint = 0;
    keyint = wordtoint(keyword);
    iID = keyint;
    
    switch(keyint){ //do a switch, and assign the correct variables. 
        case 542: //sense
            sensedir = sensedir_to_int(input_line[1]);
            sscanf(input_line[2].c_str(), "%d", &x.st);
            sscanf(input_line[3].c_str(), "%d", &y.st);
            cond = input_line[4];
            break;
        
        case 428: //flip
            sscanf(input_line[1].c_str(), "%d", &n);
            sscanf(input_line[2].c_str(), "%d", &x.st);
            sscanf(input_line[3].c_str(), "%d", &y.st);
            break;
        
        case 439: //move
            sscanf(input_line[1].c_str(), "%d", &x.st);
            sscanf(input_line[2].c_str(), "%d", &y.st);
            break;
        
        case 457: //turn
            sscanf(input_line[2].c_str(), "%d", &x.st);
            if(input_line[1] == "left"){
                lr = 0;
            }
            else{
                lr = 1;
            }
            break;
            
        case 652: //pickup
            sscanf(input_line[1].c_str(), "%d", &x.st);
            sscanf(input_line[2].c_str(), "%d", &y.st);
            break;
            
        case 427: //mark
            sscanf(input_line[1].c_str(), "%d", &marker);
            sscanf(input_line[2].c_str(), "%d", &x.st);
            break;
            
        case 654: //unmark
            sscanf(input_line[1].c_str(), "%d", &marker);
            sscanf(input_line[2].c_str(), "%d", &x.st);
            break;
        
        case 437: //drop
            sscanf(input_line[1].c_str(), "%d", &x.st);
            
        case 961: //direction
            sscanf(input_line[1].c_str(), "%d", &direction.d);
            sscanf(input_line[2].c_str(), "%d", &x.st);
            sscanf(input_line[3].c_str(), "%d", &y.st);
    }
};
    
  
aux::tstate instruction::get_xState(){
    return x;
};
aux::tstate instruction::get_yState(){
    return y;
};
void instruction::set_xState(aux::tstate newx){
    x = newx;
};
void instruction::set_yState(aux::tstate newy){
    y = newy;
};
    
std::string instruction::get_cond(){
    return cond;
};
void instruction::set_cond(std::string newc){
    cond = newc;
};
    
int instruction::get_lr(){
    return lr;
};
void instruction::set_lr(int newlr){
    lr = newlr;
}

int instruction::get_iID(){
    return iID;
}
void instruction::set_iID(int newID){
    iID = newID;
}

int instruction::get_sensedir(){
    return sensedir;
}
void instruction::set_sensedir(int sd){
    sensedir = sd;
}

int instruction::get_marker(){
    return marker;
}
void instruction::set_marker(int m){
    marker = m;
}

int instruction::get_n(){
    return n;
}
void instruction::set_n(int s){
    n = s;
}

aux::tdirection instruction::get_direction(){
    return direction;
}
void instruction::set_direction(int d){
    direction.d = d;
}