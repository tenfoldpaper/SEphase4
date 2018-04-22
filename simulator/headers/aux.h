

#ifndef AUX_H
#define AUX_H

#include <string>
using std::string;
namespace aux{
    struct tcolor{
        int c; //0 or 1 for black or red 
        tcolor(int x){
            if(x!=0&&x!=1&&x!=999)
                throw"The color is not in proper boundaries\n";
            c=x;
        };
        tcolor():c(0){};
    };

    struct tdirection{
        int d;
        tdirection(int x){
            if(x<0||x>5)
                throw "The direction is out of boundaries\n";
            d=x;
        };
        tdirection():d(0){};
    };

    struct tsensedir{
        //0 = here; 1 = ahead; 2 = leftahead; 3 = rightahead;
        int s;
        tsensedir(int x){
            if(x<0||x>3)
                throw "The sense direction is out of boundaries\n";
            s=x;
        };
    };

    struct tleftright{
        int l;
        tleftright(int x){
            if(x!=0||x!=1)
                throw "The leftright parameter is out of boundaries\n";
            l=x;
        };
    };

    struct tmark{
        int m;
        tmark():m(0){};
        tmark(int x){
            if(x<0||x>5)
                throw "The mark is out of boundaries\n";
            m=x;
        };
    };

    struct tstate{
        int st;
        tstate(int x):st(x){
            if(st<0||st>9999)
                throw "The state is out of boundaries\n";
        };
        tstate():st(0){};
        tstate(string x):st(stoi(x)){
            if(st<0||st>9999)
                throw "The state is out of boundaries\n";
        };
    };

    struct tcondition{
        int cond;
        tcondition(int x):cond(x){};
    };

    struct tposition{
        int x;
        int y;
        tposition(int t, int q):x(t),y(q){};
        tposition():x(0),y(0){};
    };
};
#endif /* AUX_H */

