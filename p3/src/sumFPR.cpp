#include "../include/sumFPR.hpp"


int SumFPR::limit_equation(int x, int y){
  return x;
}

int SumFPR::solve_FPR(int x , int y){
  return recursive_equation(x,y);
}

int SumFPR::recursive_equation(int x, int y){
  if(y == 0){
    return limit_equation(x,y);
  } else {
    return basic_.successor(recursive_equation(x, y - 1));
  }
}