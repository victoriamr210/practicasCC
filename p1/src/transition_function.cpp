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
  currentTransition = 0;
  currentState = trans[0].get_actual();
}


void FTransition::run(std::string symbol, std::string stack){
  if(trans[currentTransition].get_symbol() == symbol){
    std::cout <<"\nhola\n";
  }
}
