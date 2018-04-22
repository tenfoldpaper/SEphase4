#ifndef MARKER_H
#define MARKER_H
#include "Structs.h"

class Marker {
private:
    int bits;
public:
    Marker(const Marker& orig);
    virtual ~Marker();
    Marker();
    void set_marker(tmark mark, tcolor col);
    void clear_marker(tmark mark, tcolor col);
    bool check_marker(tmark mark, tcolor col);
    bool check_other_marker(tcolor col);
    
    void set_bits(int bit);
    
    int get_bits();
    
};

#endif /* MARKER_H */
