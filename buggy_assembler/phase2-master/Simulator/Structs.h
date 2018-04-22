/* 
 * File:   Structs.h
 */

#ifndef STRUCTS_H
#define STRUCTS_H

struct tcolor{
    int color; //red = 0, black = 1
    tcolor(int x):color(x){};
    tcolor(bool x){
      if(x)
        color = 1;
      else
        color = 0;
    };
    tcolor():color(0){};
};

struct tdirection{
    int direction; //direction in [0,5]
    tdirection(int x):direction(x){};
    tdirection():direction(0){};
};

struct tsensedir{
    int sensedir; //sensedir in [0,3]
    tsensedir():sensedir(0){};
};

struct tleftright{
    int leftright; //left = 0, right = 1
    tleftright():leftright(0){};
};

struct tmark{
    int mark; //mark in [0,5]
    tmark():mark(0){};
    tmark(int x):mark(x){};
};

struct tstate{
    int state;
    tstate(int x):state(x){};
    tstate():state(0){};
};

struct tcondition{
    int condition;
    tcondition():condition(0){};
};

struct tposition{
    int posX;
    int posY;
    tposition(int x, int y):posX(x), posY(y){};
    tposition():posX(0),posY(0){};
};

#endif /* STRUCTS_H */

