#include <iostream>
#include "../include/APV.hpp"

int main(int argc, char* argv[]) {    
	if(argc == 2) {
    std::cout << "Hello\n";
    APV automata(argv[1]);
    // automata.write();
  } else {
    std::cerr << "Introduzca nombre de fichero pls\n";
  }
}