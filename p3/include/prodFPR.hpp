#pragma once
#include <iostream>
#include "FPR.hpp"
#include "sumFPR.hpp"

class ProdFPR : public FPR{

  private:
    SumFPR sum_;

  public:
    int limit_equation(int x, int y);
    int recursive_equation(int x, int y);
    int solve_FPR(int x, int y);
};