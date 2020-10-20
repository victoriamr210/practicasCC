#pragma once
#include <iostream>
#include <vector>
#include "transition.hpp"

class FTransition{
  private:
    std::string currentState;
    int currentTransition;
    std::vector<transition> trans;
  public:
    FTransition(){}
    void push(transition aux);
    void write(void);
    int get_current_tran(void);
    std::string get_current_state(void);

    void start(void);
    std::vector<transition> get_transitions(std::string symbol, std::string stack, std::string current);
};