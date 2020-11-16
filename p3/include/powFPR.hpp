#pragma once
#include <iostream>
#include "FPR.hpp"
#include "prodFPR.hpp"

class PowFPR : public FPR{

  private:
    ProdFPR sum_;

  public:
    int limit_equation(int x, int y);
    int recursive_equation(int x, int y);
    int solve_FPR(int x, int y);
};