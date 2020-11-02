#include <iostream>
#include "../include/state.hpp"

State::State(std::string aux){
  id_ = aux;
}

std::string State::get_id(void){
  return id_;
}

bool State::check_id(std::string aux){
  return id_ == aux;
}

std::vector<Transition> State::get_trans(std::string symbol){
   std::vector<Transition> v;
  for(int i = 0; i < trans_.size(); i++){
    if ((trans_[i].get_readSymbol() == symbol)){
      v.push_back(trans_[i]);
    }
  }
  return v;
}

void State::push(Transition t){
  trans_.push_back(t);
}

void State::write(void){
  for(int i =0; i < trans_.size(); i++){
    trans_[i].write();
  }
}