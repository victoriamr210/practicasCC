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
  // write();
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

void Machine::run(void){
  std::string currentState = initialState_;
  while(finalState_.compare(currentState) != 0){
    int pos = find_state(currentState);
    std::vector<std::string> readTape = get_read_tapes();
    // states_[pos].write();
    Transition actual = states_[pos].get_trans(readTape);
    // actual.write();
    std::vector<std::string> writeTape = actual.get_writeSymbols();
    std::vector<std::string> moveTape = actual.get_movements();
    for(int i = 0; i < numberTapes_; i++){
      tapes_[i].move_head(writeTape[i], moveTape[i]);
    }
    currentState = actual.get_next();
  }
  write_tapes();

}

void Machine::write(void) {
  // std::cout << *(stateSet_.begin()) << " ";
  std::cout << "\nEstados: ";
  for(auto i = stateSet_.begin(); i != stateSet_.end(); i++){
    std::cout << *i << " ";
  }
  std::cout <<"\n";

  std::cout << "Alfabeto: ";
  for(auto i = symbols_.begin(); i != symbols_.end(); i++){
    std::cout << *i << " ";
  }
  std::cout <<"\n";

  std::cout << "Alfabeto cinta: ";
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
}

int Machine::find_state(std::string state){
  for(int i = 0; i < states_.size(); i++){
    // std::cout << states_[i].get_id() << "estado acutal\n";
    if(states_[i].check_id(state)){
      // std::cout << "return\n";
      return i;
    }
  }
}

std::vector<std::string> Machine::get_read_tapes(void){
  std::vector<std::string> aux;
  for(int i = 0; i <tapes_.size(); i++){
    aux.push_back(tapes_[i].get_actual());
  }
  return aux;
}

void Machine::write_tapes(void){
  std::cout << "\nCINTAS:\n";
  for(int i = 0; i< numberTapes_; i++){
    tapes_[i].write();
  }
}
