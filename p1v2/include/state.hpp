#pragma once
#include <iostream>
#include <vector>
#include "transition.hpp"

class state{
  private:
    std::string id;
    std::vector<transition> trans;


  public:
    state(std::string state);

    std::string get_id(void);

    bool check_id(std::string aux);
    std::vector<transition> get_trans(std::string symbol, std::string topStack);
    void push(transition t);
    void write(void);
};
