#pragma once
#include <iostream>
#include <stack>
#include <set>
#include <string>
#include "transition.hpp"
// #include "transition_function.hpp"
#include "state.hpp"

class APV{
  private:
    std::stack<std::string> pila;
    std::set<std::string> stateSet;
    // FTransition trans;
    std::vector<state> states;
    std::set<std::string> symbols;
    std::set<std::string> stackSymb;
    std::string initialState;
    std::string initialStack;
    std::string checkString;
  
  public:
    APV(char file1[]);
    void read(char file1[]);
    void write();
    void build_states(std::string aux);
    void build_symbols(std::string aux);
    void build_stack_symbols(std::string aux);

    bool check_automaton(void);
    void begin(void);
    void run(std::string currentState, std::string testString, std::stack<std::string> p);
    std::stack<std::string> copyStack(std::stack<std::string> p, std::vector<std::string> insert);

    void set_string(std::string aux);
    void write_stack(std::stack<std::string> p);
    void make_state(std::string s, transition t);
    std::vector<transition> get_transitions(std::string symbol, std::string topStack, std::string state);
    // std::set<std::string> split(std::string aux);
};