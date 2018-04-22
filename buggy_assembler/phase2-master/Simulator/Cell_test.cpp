#include <cstdlib>
#include <iostream>
#include "Bug.h"
#include "Cell.h"
#include "Marker.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    try
    {
        Cell c('a');
    }
    catch(char const* e)
    {
        cout<<e<<endl;
    }
    Cell a('#');
    Cell b('.');
    Cell c('_');
    Cell d('+');
    Cell f('4');
 
    /*Check getter validity*/
    if(a.get_obstructed()!=1)
        cout<<"The obstructed getter doesn't work for an obstacle\n";
    if(b.get_obstructed()!=0)
        cout<<"The obstructed getter doesn't work for a clear cell\n";
    if(c.get_obstructed()!=1)
        cout<<"The obstructed getter doesn't work for black bugs\n";
    if(d.get_obstructed()!=1)
        cout<<"The obstructed getter doesn't work for red bugs\n";
    if(f.get_obstructed()!=0)
        cout<<"The obstructed getter doesn't work for food cell\n";
 
    if(a.is_black_home_area()==1)
        cout<<"The is_black_home_area getter doesn't work for obstacles\n";
    if(b.is_black_home_area()==1)
        cout<<"The is_black_home_area getter doesn't work for clear cells\n";
    if(c.is_black_home_area()==0)
        cout<<"The is_black_home_area getter doesn't work for black areas\n";
    if(d.is_black_home_area()==1)
        cout<<"The is_black_home_area getter doesn't work for red areas\n";
    if(f.is_black_home_area()==1)
        cout<<"The is_black_home_area getter doesn't work for food cells\n";
    
    if(a.is_red_home_area()==1)
        cout<<"The is_red_home_area getter doesn't work for obstacles\n";
    if(b.is_red_home_area()==1)
        cout<<"The is_red_home_area getter doesn't work for clear cells\n";
    if(c.is_red_home_area()==1)
        cout<<"The is_red_home_area getter doesn't work for black areas\n";
    if(d.is_red_home_area()==0)
        cout<<"The is_red_home_area getter doesn't work for red areas\n";
    if(f.is_red_home_area()==1)
        cout<<"The is_red_home_area getter doesn't work for food cells\n";

    /*check bugs getter&setter*/
    if(c.get_occupant()!=NULL)
        cout<<"Get_occupant isn't null after instantiation\n";
  
    Bug r(0,1,14);
    c.set_occupant(r);
    Bug t=*c.get_occupant();
    if(t.get_color().color!=r.get_color().color||t.get_direction().direction!=r.get_direction().direction||
       t.get_food()!=r.get_food()||t.get_position().posX!=r.get_position().posX||t.get_position().posY!=r.get_position().posY||
       t.get_progid()!=r.get_progid()||t.get_state().state!=r.get_state().state||
       t.is_dead()!=r.is_dead())
        cout<<"The occupant setter doesn't work\n";

    /*check getter&setter for food*/
    if(f.get_food()!=4)
        cout<<"The food getter is not consistent with the passed value\n";

    f.set_food(14);
    if(f.get_food()!=14)
        cout<<"The food setter doesn't work properly\n";
  
    try
    {
        f.set_food(-3);
    }
    catch(char const* e)
    {
        cout<<e<<endl;
    }
   
    return 0;
}

