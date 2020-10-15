#pragma once
#include <iostream>

class transition{
  private:
    std::string actualState;
    std::string stringSymbol;
    std::string topStack;
    std::string insertStack;
    std::string nextState;
  
  public:
    transition(){}
    transition(std::string aux);
    transition(std::string actual, char symbol, std::string top, std::string insert, std::string next);
    std::string get_actual();
    std::string get_top();
    std::string get_insert();
    std::string get_next();

    void set_actual(std::string actual);
    void set_top(std::string top);
    void set_insert(std::string insert);
    void set_next(std::string next);
    void set_symbol(std::string stringSymbol);
    void write();
};