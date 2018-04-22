#include "Marker.h"
#include "Cell.h"
#include "Bug.h"
#include <cstdlib>
/*
  * # - obstacle
  * . - clear cell
  * _ black bug home area cell
  * + red bug home area cell
  * 1...9 clear cell containing n food particles
  * 
  * as many bugs as many home area cells
*/
 
 Cell::Cell(){}
 
 Cell::Cell(char symb)
 {
     switch(symb){
         case '#' :
             obstructed=1;
             food=0;
             home_black_bug=0;
             home_red_bug=0;
             break;
         case '.':
             obstructed=0;
             food=0;
             home_black_bug=0;
             home_red_bug=0;
             break;
         case '_':
             obstructed=1;
             food=0;
             home_black_bug=1;
             home_red_bug=0;
             break;
         case '+':
             obstructed=1;
             food=0;
             home_black_bug=0;
             home_red_bug=1;
             break;
         default:
            if(symb-'0'<=9&&symb-'0'>=0)
             {
                 obstructed=0;
                 food=symb-'0';
                 home_black_bug=0;
                 home_red_bug=0;
             }
             else
             {
                 throw "Invalid cell specifier passed\n";
             }
             break;
     }
     mark=NULL;
     occupant=NULL;
 }
     
Bug* Cell::get_occupant()
 {
     return occupant;
 }
     
 void Cell::set_occupant(Bug new_occupant)
 {

     occupant=new Bug(new_occupant);
 }
     
 int Cell::get_food()
 {
     return food;
 }
     
 void Cell::set_food(int new_food)
 {
     if(new_food<0)
     {
         throw "The amount of food can't be negative\n";
     }
     food=new_food;
 }
     
 bool Cell::get_obstructed()
 {
     return obstructed;
 }
     
 bool Cell::is_black_home_area()
 {
     return home_black_bug;
 }
     
 bool Cell::is_red_home_area()
 {
     return home_red_bug;
}
