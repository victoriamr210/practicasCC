#include <iostream>
#include "../include/state.hpp"

State::State(std::string aux){
  id_ = aux;
}

std::string State::get_id(void){
  return id_;
}

bool State::check_id(std::string aux){
  if(id_.compare(aux) == 0){
    return true;
  }
  return false;
  return id_.compare(aux);
  return id_ == aux;
}

Transition State::get_trans(std::vector<std::string> symbols){
  for(int i = 0; i < trans_.size(); i++){
    if (trans_[i].get_readSymbols() == symbols){
      return trans_[i];
    }
  }
}

void State::push(Transition t){
  trans_.push_back(t);
}

void State::write(void){
  for(int i =0; i < trans_.size(); i++){
    trans_[i].write();
  }
}