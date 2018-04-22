#ifndef CELL_H
#define CELL_H
#include "Bug.h"
#include "Marker.h"
class Cell 
{
private:
    Bug* occupant;
    bool obstructed;
    int food;
    bool home_black_bug;
    bool home_red_bug;
public:
    Marker* mark;
    Cell(char symb);
    Cell();
    ~Cell(){delete mark; delete occupant;};
    Bug* get_occupant();
    void set_occupant(Bug new_occupant);
    int get_food();
    void set_food(int new_food);
    bool get_obstructed();
    bool is_black_home_area();
    bool is_red_home_area();
};


#endif /* CELL_H */

