/*
 * Marker class implementation
 */


#include "Marker.h"

Marker::Marker() {
	bits=0;
}

Marker::Marker(const Marker& orig) {
}

Marker::~Marker() {
}

void Marker::set_bits(int bit){
    bits= bit;
}
    
int Marker::get_bits(){
    return bits;
}

void Marker::set_marker(tmark mark, tcolor col){
    if(mark.mark<0||mark.mark>5)
    {
        throw "Mark can only take values between 0...5\n";
    }
    if(col.color!=0&&col.color!=1)
    {
        throw "Color can only take value 0 or 1\n";
    }
    bits = bits | 1<<(mark.mark+6*col.color);
     
}
 
void Marker::clear_marker(tmark mark, tcolor col){
	bits = bits & ~1<<(mark.mark+6*col.color);
     
}
 
bool Marker::check_marker(tmark mark, tcolor col){
    return bits & 1<<(mark.mark+6*col.color);
	    
}
   
bool Marker::check_other_marker(tcolor col){
	for (int i = 0; i < 6; i++){
            if (bits & 1<<(i + 6*col.color)){
                return true;
            }
        }
    return false;
	
}
