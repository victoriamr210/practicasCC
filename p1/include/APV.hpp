#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include "transition.hpp"

class APV{
  private:
    std::stack<std::string> pila;
    std::vector<std::string> states;
    std::vector<transition> trans;
    std::vector<std::string> symbols;
    std::vector<std::string> stackSymb;
    std::string intialState;
    std::string initialStack;
  
  public:
    APV(char file[]);
    void read(char file[]);
    void write();
    void build_states(std::string aux);
    void build_symbols(std::string aux);
    void build_stack_symbols(std::string aux);
};