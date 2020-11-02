#pragma once
#include <iostream>
#include "tape.hpp"
#include "state.hpp"
#include <vector>
#include <string>
#include <set>

class Machine{
  private:
    Tape tape_; //cinta
    std::vector<State> states_; //conjutno de estados
    std::set<std::string> stateSet_; //conjunto Q
    std::set<std::string> symbols_;   //conjunto de simbolos
    std::set<std::string> tapeSymb_; //conjunto de simbolos de la cinta
    std::string initialState_;        //estado incial
    std::string blank_; //simbolo en blanco
    std::set<std::string> finalStates_; //conunto F

  public:
    Machine(char file[]);
    void read(char file[]);
    void build_states(std::string aux);
    void build_tape_symbols(std::string aux);
    void build_symbols(std::string aux);
    void make_state(std::string id, Transition t);
    void write(void);
};