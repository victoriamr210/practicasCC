#include "../include/basicFPR.hpp"

int BasicFPR::zero(int n){
  return 0;
}

int BasicFPR::successor(int n){
  return n+1;
}

int BasicFPR::projection(std::vector<int> v, int n){
  return v[n];
}