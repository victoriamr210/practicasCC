#include <iostream>
#include "../include/APVs.hpp"

int main(int argc, char* argv[]) {    
	if(argc == 3) {
    std::cout << "Hello\n";
    try{
      APV automata(argv[1], argv[2]);
    } catch(char const* e){
      std::cout << e;
    }
    // automata.write();
  } else {
    std::cerr << "ERROR: Introduzca nombre de fichero pls\n";
  }
}