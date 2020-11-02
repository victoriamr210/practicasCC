#pragma once
#include <iostream>
#include <vector>
#include "transition.hpp"

class State{
  private:
    std::string id_;
    std::vector<Transition> trans_;

  public:
    State(std::string state);
    std::string get_id(void);
    bool check_id(std::string aux);
    std::vector<Transition> get_trans(std::string symbol);
    void push(Transition t);
    void write(void);
};