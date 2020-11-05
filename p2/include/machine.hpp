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
    std::string finalState_; //estado final
    std::set<std::string> finalStates_; //conjunto F
    std::vector<Tape> tapes_;
    int numberTapes_;

  public:
    Machine(char file[]);
    void read(char file[]);
    void build_states(std::string aux);
    void build_tape_symbols(std::string aux);
    void build_symbols(std::string aux);
    void make_state(std::string id, Transition t);
    void write(void);
    bool check_machine(void);
    void set_string(std::string aux);
    void run(void);
    int find_state(std::string state);
    std::vector<std::string> get_read_tapes(void);
};