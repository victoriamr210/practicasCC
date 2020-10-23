#pragma once
#include <iostream>
#include <vector>
#include <string>

class transition{
  private:
    std::string actualState;
    std::string stringSymbol;
    std::string topStack;
    std::vector<std::string> insertStack;
    std::string nextState;
  
  public:
    transition(){}
    transition(std::string aux);
    transition(std::string actual, char symbol, std::string top, std::vector<std::string> insert, std::string next);
    std::string get_actual();
    std::string get_top();
    std::vector<std::string> get_insert();
    std::string get_next();
    std::string get_symbol();

    void set_actual(std::string actual);
    void set_top(std::string top);
    void set_insert(std::vector<std::string> insert);
    void set_next(std::string next);
    void set_symbol(std::string stringSymbol);
    void write();
};