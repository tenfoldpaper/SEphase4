#include "Bug.h"

Bug::Bug()
{
    
}

Bug::Bug(tcolor i_color, int i_progid, int i_resting)
{
    if(i_color.color!=0&&i_color.color!=1)
    {
        throw "Color can only take value 0 or 1\n";
    }
    color=i_color;
    prog_id=i_progid;
    remaining_rest=0;
    if(i_resting<0)
        throw "There can't be a negative value as the resting time.\n";
    resting=i_resting;
    direction.direction=0;
    dead=0;
    has_food=0;
    state.state=0;
    
}

void Bug::start_resting(){
    remaining_rest=resting;
}

bool Bug::rested(){
    if(remaining_rest>0)
    {
        remaining_rest--;
        return 0;
    }
    else
        return 1;
}

int Bug::get_progid()
{
    return prog_id;
}

tcolor Bug::get_color(){
    return color;
}

tstate Bug::get_state(){
    return state;
}

void Bug::set_state(tstate new_state)
{
    if(new_state.state<0||new_state.state>9999)
    {
        throw "State should be in 0..9999\n";
    }
    state=new_state;
}

tdirection Bug::get_direction(){
    return direction;
}
    
void Bug::set_direction(tdirection new_direction)
{
    if(new_direction.direction>5||new_direction.direction<0)
    {
        throw "Direction should be in 0..5\n";
    }
    direction=new_direction;
}

tposition Bug::get_position()
{
    return position;
}

void Bug::set_position(tposition new_position)
{
    position=new_position;
}

bool Bug::get_food(){
    return has_food;
}
    
void Bug::set_food(bool new_food)
{
    if(new_food<0)
        throw "There can't be a negative value as the resting time.\n";
    has_food=new_food;
}
   
bool Bug::is_dead(){
    return (dead==1);
}

void Bug::kill()
{
    if(dead==1)
    {
        throw "Bug cannot be killed again\n";
    }
    dead=1;
}
