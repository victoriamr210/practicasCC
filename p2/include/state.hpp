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
    Transition get_trans(std::vector<std::string> symbols);
    void push(Transition t);
    void write(void);
};