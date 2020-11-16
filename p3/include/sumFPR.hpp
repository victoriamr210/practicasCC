#pragma once
#include <iostream>
#include "FPR.hpp"
#include "basicFPR.hpp"

class SumFPR : public FPR{

  private:
    BasicFPR basic_;

  public:
    int limit_equation(int x, int y);
    int recursive_equation(int x, int y);
    int solve_FPR(int x, int y);
};