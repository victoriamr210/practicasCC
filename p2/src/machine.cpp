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
    std::getline(f, finalState_);
    std::getline(f, aux);
    numberTapes_ = stoi(aux);
    while(!f.eof()){
      std::getline(f, aux);
      // std::cout << "in\n";
      Transition t(aux, numberTapes_);
      // std::cout << "out\n";
      make_state(t.get_actual(), t);
      // std::cout << "state\n";
      // states.find()
      // trans_.push(t);
    }
    f.close();
  }else{
    std::cerr << "Error de apertura\n";
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
  // std::cout << *(stateSet_.begin()) << " ";
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
    std::cout << "\nEstado " << states_[i].get_id() << ":\n";
    states_[i].write();
  }


}

void Machine::make_state(std::string s, Transition t){
  for(int i = 0; i < states_.size(); i++){
    if(states_[i].check_id(s)){
      states_[i].push(t);
      // std::cout << "why\n";
    }
  }
}

bool Machine::check_machine(void){
  // std::cout << *(stateSet_.begin()) << " " << initialState_ << "\n";

   if (stateSet_.find(initialState_) == stateSet_.end()){
  //   std::cerr << "ERROR: Estado inicial no esta en el conjunto de estados\n";
  //   return false;
  }
  return true;
}

void Machine::set_string(std::string aux){
  tapes_.resize(numberTapes_);
  Tape t(aux);
  tapes_[0] = t;
  for(int i = 1; i< numberTapes_; i++){
    Tape tt;
    tapes_[i] = tt;
  }
  std::cout << "\nCINTAS:\n";
  for(int i = 0; i< numberTapes_; i++){
    tapes_[i].write();
  }
}