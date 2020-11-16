#include "../include/prodFPR.hpp"

int ProdFPR::limit_equation(int x, int y){
  return x;
}

int ProdFPR::recursive_equation(int x, int y){
  if(y == 1){
    return limit_equation(x,y);
  } else {
    SumFPR sum;
    return sum.solve_FPR(x, recursive_equation(x, y-1));
  }
}

int ProdFPR::solve_FPR(int x, int y){
  return recursive_equation(x,y);
}