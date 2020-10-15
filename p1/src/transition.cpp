#include "../include/transition.hpp"
#include <vector>

transition::transition(std::string actual, char symbol, std::string top, std::string insert, std::string next){
  stringSymbol = symbol;
  topStack = top;
  insertStack = insert;
  nextState = next;
  actualState = actual;
}

transition::transition(std::string aux) {
  std::string insert, space = " ";
  int pos = 0;
  std::vector<std::string> to_insert;

  while ((pos = aux.find(space)) != std::string::npos){
    insert = aux.substr(0, pos);
    to_insert.push_back(insert);
    aux.erase(0, pos + space.length());
  }
  // std::cout << to_insert[0] << "\n";
  to_insert.push_back(aux);
  set_actual(to_insert[0]);
  set_symbol(to_insert[1]);
  set_top(to_insert[2]);
  set_next(to_insert[3]);
  std::string stackInsert = "";
  for(int i=4; i<to_insert.size(); i++){
    stackInsert += to_insert[i];
  }
  set_insert(stackInsert);
  write();
}

std::string transition::get_actual(){
  return actualState;
}

std::string transition::get_top(){
  return topStack;
}

std::string transition::get_insert(){
  return insertStack;
}

std::string transition::get_next()
{
  return nextState;
}

void transition::set_actual(std::string actual){
  actualState = actual;
}

void transition::set_top(std::string top){
  topStack = top;
}

void transition::set_insert(std::string insert){
  insertStack = insert;
}

void transition::set_next(std::string next){
  nextState = next;
}

void transition::set_symbol(std::string symbol){
  stringSymbol = symbol;
}

void transition::write(void){
  std::cout << actualState << " " << stringSymbol << " " << topStack << " " << nextState << " " << insertStack << "\n";
}