#include "../include/powFPR.hpp"

int PowFPR::limit_equation(int x, int y){
  return x;
}

int PowFPR::recursive_equation(int x, int y){
  if(y == 1){
    return limit_equation(x,y);
  } else {
    ProdFPR prod;
    return prod.solve_FPR(x, recursive_equation(x, y-1));
  }
}

int PowFPR::solve_FPR(int x, int y){
  return recursive_equation(x,y);
}