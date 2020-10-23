#include "../include/state.hpp"

state::state(std::string aux){
  id = aux;
}

std::string state::get_id(void){
  return id;
}

bool state::check_id(std::string aux){
  return id == aux;
}

std::vector<transition> state::get_trans(std::string symbol, std::string topStack){
   std::vector<transition> v;
  for(int i = 0; i < trans.size(); i++){
    if ((trans[i].get_symbol() == symbol && trans[i].get_top() == topStack) || 
        (trans[i].get_symbol() == "." && trans[i].get_top() == topStack)){
      v.push_back(trans[i]);
    }
  }
  return v;
}

void state::push(transition t){
  trans.push_back(t);
}

void state::write(void){
  for(int i =0; i < trans.size(); i++){
    trans[i].write();
  }
}

