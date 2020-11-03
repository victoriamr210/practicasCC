#include <iostream>
#include <fstream>
#include "../include/machine.hpp"

std::string get_string(char file[]){
  std::fstream f;
  std::string aux;
  f.open(file);
  if(f.is_open()){
    std::getline(f, aux);
  }
  return aux;
}

int main(int argc, char* argv[]) {
  if(argc == 3){
    Machine mt(argv[1]);
    if(mt.check_machine()){
      std::string checkString = get_string(argv[2]);
      mt.set_string(checkString);
    }
  }
}