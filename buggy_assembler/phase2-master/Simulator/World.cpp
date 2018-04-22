#include "World.h"
#include "Bug.h"
#include <vector>

using namespace std;


World::World() {
}


World::~World() {
	for (int i = 0; i < length; i++)
                delete[] cell[i];
        delete[] cell;

}

void World::set_width(int w){
    width=w;
}

void World::set_length(int len){
    length=len;
}

int World::get_width(){
    return width;
}

int World::get_length(){
    return length;
}



void World::load(string filename){
    width=0;
    length=0;
    int id=0;//bug identity
    vector<char> buf;

        int pos=0;
        int n=buf.size();

        //get width
        while(pos<n && buf[pos]!='\n')
        {
            if(buf[pos]<'0'||buf[pos]>'9')
            {
                throw "The file contains incorrect width info\n";
            }
            width=width*10+(buf[pos]-'0');
            pos++;
        }
        if(pos>=n)
            throw "The file is incomplete\n";
        pos++;

        //get length
        while(pos<n && buf[pos]!='\n')
        {
            if(buf[pos]<'0'||buf[pos]>'9')
            {
                throw "The file contains incorrect length info\n";
            }
            length=length*10+(buf[pos]-'0');
            pos++;
        }
        if(pos>=n)
            throw "The file is incomplete\n";

        //allocate Cell matrix
        cell=new Cell*[length];
        for(int i=0;i<length;i++)
        {
            cell[i]=new Cell[width]();
        }

        pos++;
        for(int i=0;i<length;i++)
        {
            for(int j=0;j<width;j++)
            {
                if(pos>=n)
                {
                    //free Cell space
                    for(int k=0;k<length;k++)
                    {
                        delete[] cell[k];
                    }
                    delete[] cell;
                    throw "The file is incomplete \n";
                }
                char c=buf[pos];
                pos++;
                cell[i][j]=Cell(c);
                //color 0 red - 1 black
                if(cell[i][j].is_black_home_area())
                {
                    Bug b(1,id,14);
                    id++;
                    cell[i][j].set_occupant(b);
                }
                if(cell[i][j].is_red_home_area())
                {
                    Bug b(0,id,14);
                    id++;
                    cell[i][j].set_occupant(b);
                }
            }
            if(buf[pos]!='\n')
            {
                //free Cell space
                for(int k=0;k<length;k++)
                {
                    delete[] cell[k];
                }
                delete[] cell;
                throw "The file is incorrect \n";
            }
            pos++;
        }
        if(pos<n)
        {
            for(int k=0;k<length;k++)
            {
                delete[] cell[k];
            }
            delete[] cell;
            throw "There are too many characters in the file\n";
        }


    }


Cell World::get_cell(tposition pos){
        int i = pos.posX, j = pos.posY;

        if ((i < 0 || j < 0) || (i >= length || j >= width)){
            throw "Invalid position!";
        }

        return this->cell[i][j];
    }

tposition World::adjacent(tdirection dir, tposition pos){

    int i = pos.posX, j = pos.posY;
    tposition tmp;

    if ((i < 0 || j < 0) || (i >= length || j >= width)){
        throw "Invalid position!\n";
    }
    if(dir.direction>5||dir.direction<0)
    {
        throw "Direction can only take values between 0...5\n";    
    }

    if (dir.direction == 0){
        tmp.posX = i + 1;
        tmp.posY = j;
        return tmp;
    }

    if (dir.direction == 1){
        if (j%2 == 0){
            tmp.posX = i;
            tmp.posY = j + 1;
            return tmp;
        }
        else {
            tmp.posX = i+1;
            tmp.posY = j+1;
            return tmp;
        }
    }
    else if (dir.direction == 2){
        if (j%2 == 0){
            tmp.posX = i - 1;
            tmp.posY = j + 1;
            return tmp;
        }
        else {
            tmp.posX = i;
            tmp.posY = j + 1;
            return tmp;
        }
    }
    else if (dir.direction == 3){
        tmp.posX = i - 1;
        tmp.posY = j;
        return tmp;
    }
    else if (dir.direction == 4){
        if (j%2 == 0){
            tmp.posX = i - 1;
            tmp.posY = j - 1;
            return tmp;
        }
        else {
            tmp.posX = i;
            tmp.posY = j - 1;
            return tmp;
        }
    }
    else{
        if (j%2 == 0){
            tmp.posX = i;
            tmp.posY = j - 1;
            return tmp;
        }
        else {
            tmp.posX = i +1;
            tmp.posY = j -1;
            return tmp;
        }
    }
 }

tcolor World::other_color(tcolor col){
	return 1 - col.color;
}
int World::red_food() {
    int count = 0;
    for (int i = 0; i < length; i++){
        for(int j = 0; j < width; j++){
            if (cell[i][j].is_red_home_area()){
                count += cell[i][j].get_food();
            }
        }
    }
    return count;
}

int World::black_food() {
    int count = 0;
    for (int i = 0; i < length; i++){
        for(int j = 0; j < width; j++){
            if (cell[i][j].is_black_home_area()){
                count += cell[i][j].get_food();
            }
        }
    }
    return count;
}

int World::black_count() {
    int count = 0;
    for (int i = 0; i < length; i++){
        for(int j = 0; j < width; j++){
            Bug* bug= cell[j][i].get_occupant();

            if (bug == NULL || bug->get_color().color == 1){
                continue;
            }
            count++;

        }
    }
    return count;
}

int World::red_count() {
    int count = 0;
    for (int i = 0; i < length; i++){
        for(int j = 0; j < width; j++){
            Bug* bug = cell[j][i].get_occupant();

            if (bug == NULL || bug->get_color().color == 0){
                continue;
            }
            count++;
        }
    }
    return count;
}

void error(std::string message) {
        throw message;
    }

tcolor World::winner() {
        if (red_food() > black_food()){
            return 1;
        }
        else if (black_food() > red_food()){
            return 0;
        }
        else {
            return -1;
        }
}
