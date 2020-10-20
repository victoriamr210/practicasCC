#include "../include/transition_function.hpp"

void FTransition::push(transition aux){
  trans.push_back(aux);
}

void FTransition::write(void){
  for(int i =0; i < trans.size(); i++){
    trans[i].write();
  }
}


int FTransition::get_current_tran(void){
  return currentTransition;
}

std::string FTransition::get_current_state(void){
  return currentState;
}

void FTransition::start(void){
  // currentTransition = 0;
  currentState = trans[0].get_actual();
}


std::vector<transition> FTransition::get_transitions(std::string symbol, std::string stack, std::string current){
  std::vector<transition> v;
    std::cout << "\nget\n";
    std::cout << "Estado actual: " << currentState << "\n";
    std::cout << "String actual: " << symbol << "\n";
    std::cout << "stack actual: " << stack << "\n";
  for(int i = 0; i < trans.size(); i++){
    if((trans[i].get_symbol() == symbol && trans[i].get_top() == stack && trans[i].get_actual() == current) || (trans[i].get_symbol() == "." && trans[i].get_top() == stack)){
      v.push_back(trans[i]);
    }
  }
  return v;
}
