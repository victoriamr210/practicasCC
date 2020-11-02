#include <iostream>
#include "../include/machine.hpp"

int main(int argc, char* argv[]) {
  if(argc == 2){
    Machine mt(argv[1]);
    if(mt.check_machine()){
      // mt.set_string()
    }
  }
}