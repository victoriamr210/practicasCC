#include <iostream>
#include "../include/APVs.hpp"

int main(int argc, char* argv[]) {    
	if(argc == 3) {
    std::cout << "Hello\n";
    APV automata(argv[1], argv[2]);
    // automata.write();
  } else {
    std::cerr << "ERROR: Introduzca nombre de fichero pls\n";
  }
}