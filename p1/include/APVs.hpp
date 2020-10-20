#pragma once
#include <iostream>
#include <stack>
#include <set>
#include <string>
#include "transition.hpp"
#include "transition_function.hpp"
// #include "state.hpp"

class APV{
  private:
    std::stack<std::string> pila;
    std::set<std::string> states;
    FTransition trans;
    std::set<std::string> symbols;
    std::set<std::string> stackSymb;
    std::string initialState;
    std::string initialStack;
    std::string checkString;
  
  public:
    APV(char file1[], char file2[]);
    void read(char file1[], char file2[]);
    void write();
    void build_states(std::string aux);
    void build_symbols(std::string aux);
    void build_stack_symbols(std::string aux);

    bool check_automaton(void);
    void begin(void);
    void run(std::string currentState, std::string testString, std::stack<std::string> p);
    std::stack<std::string> copyStack(std::stack<std::string> p, std::vector<std::string> insert);

    void set_string(char file[]);
    // std::set<std::string> split(std::string aux);
};