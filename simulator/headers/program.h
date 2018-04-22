#ifndef PROGRAM_H
#define PROGRAM_H
//phase 4
#include "bug.h"
#include "./inst/instruction.h"
#include  <vector>
#include "world.h"
class Program{
private:
  int id;
  World w;
  std::vector<instruction*> black_inst;
  std::vector<instruction*> red_inst;
public:
  Program(int, std::string, std::string, std::string);
  ~Program(){};
  std::vector<instruction*> get_blackinst(){
      return black_inst;
  }
  std::vector<instruction*> get_redinst(){
      return red_inst;
  }
  void step(Bug*);
  void run_game(int);
};


#endif

