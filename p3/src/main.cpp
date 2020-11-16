#include <iostream>
#include "../include/sumFPR.hpp"
#include "../include/prodFPR.hpp"
#include "../include/powFPR.hpp"
#include <stdlib.h>

int main(int argc, char *argv[]){
  PowFPR pow;
  if(argc == 3){
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    std::cout << "Potencia: " << pow.solve_FPR(x,y) << "\n";
  } else {
    std::cerr << "ERROR:: Numero de parametros incorrecto, se necesitan 2\n";
  }
}