#include "../include/machine.hpp"
#include <fstream>
#include <string>
#include <algorithm>

Machine::Machine(char file[]){
  read(file);
}

void Machine::read(char file[]){
  std::fstream f;
  f.open(file);
  std::string aux;

  if(f.is_open()){
    while(std::getline(f, aux)){
      if(aux[0] != '#'){
        build_states(aux);
        break;
      }
    }
    std::getline(f, aux);
    build_symbols(aux);
    std::getline(f, aux);
    build_tape_symbols(aux);
    std::getline(f, initialState_);
    std::getline(f, blank_);
    while(!f.eof()){
      std::getline(f, aux);
      Transition t(aux);
      // make_state(t.get_actual(), t);
      // states.find()
      // trans.push(t);
    }

    f.close();
  }
  write();
}

void Machine::build_states(std::string aux){
  std::string toInsert = "";
  for(int i = 0; i < aux.size(); i++){
    if(aux[i] != ' '){
      toInsert += aux[i];
    } else {
      State s(toInsert);
      states_.push_back(s);
      stateSet_.insert(toInsert);
      toInsert = "";
    }
  }
  State s(toInsert);
  states_.push_back(s);
  stateSet_.insert(toInsert);
  // write();
}

void Machine::build_symbols(std::string aux){
  std::string toInsert = "";
  for(int i = 0; i < aux.size(); i++){
    if(aux[i] != ' '){
      toInsert = aux[i];
      symbols_.insert(toInsert);
    }
  }
}

void Machine::build_tape_symbols(std::string aux){
  std::string toInsert = "";
  for(int i = 0; i < aux.size(); i++){
    if(aux[i] != ' '){
      toInsert = aux[i];
      tapeSymb_.insert(toInsert);
    }
  }
}

void Machine::write(void) {
  // std::cout << states[0] << " ";
  std::cout << "\nEstados:\n";
  for(auto i = stateSet_.begin(); i != stateSet_.end(); i++){
    std::cout << *i << " ";
  }
  std::cout <<"\n";

  std::cout << "Alfabeto:\n";
  for(auto i = symbols_.begin(); i != symbols_.end(); i++){
    std::cout << *i << " ";
  }
  std::cout <<"\n";

  std::cout << "Alfabeto cinta:\n ";
  for(auto i = tapeSymb_.begin(); i != tapeSymb_.end(); i++){
    std::cout << *i << " ";
  }
  std::cout <<"\n";

  std::cout << "Estado inicial: " << initialState_ << "\n";
  std::cout << "Vacio: " << blank_ << "\n";

  std::cout << "\nTransiciones:\n";

  for(int i = 0; i < states_.size(); i++){
    std::cout << "\n\tEstado " << states_[i].get_id() << ":\n";
    
    states_[i].write();
  }

}

void Machine::make_state(std::string s, Transition t){
  for(int i = 0; i < states_.size(); i++){
    if(states_[i].check_id(s)){
      states_[i].push(t);
      break;
    }
  }
}