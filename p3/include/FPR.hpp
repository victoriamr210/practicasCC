#pragma once
#include <iostream>

class FPR{
  public:
  virtual int limit_equation(int x, int y) = 0;
  virtual int recursive_equation(int x, int y) = 0;
  virtual int solve_FPR(int x, int y) = 0;
};