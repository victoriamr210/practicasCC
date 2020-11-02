#include "../include/transition.hpp"
#include <vector>

Transition::Transition(std::string aux) {
  std::string insert, space = " ";
  int pos = 0;
  std::vector<std::string> to_insert;

  // while ((pos = aux.find(space)) != std::string::npos){
  //   insert = aux.substr(0, pos);
  //   to_insert.push_back(insert);
  //   aux.erase(0, pos + space.length());
  // }
  insert = "";
  for(int i = 0; i < aux.size(); i++){
    if(aux[i] != ' '){
      insert += aux[i];
    } else {
      to_insert.push_back(insert);
      // std::cout << to_insert.back() << "\n";
      insert = "";
    }
  }

  std::cout << to_insert.size() << "\n";
  // to_insert.push_back(aux);
  // set_actual(to_insert[0]);
  // set_readSymbol(to_insert[1]);
  // set_next(to_insert[2]);
  // set_writeSymbol(to_insert[3]);
  // set_movement(to_insert[4]);
  // set_insert(stackInsert);
  // write();
}

std::string Transition::get_actual(){
  return actualState_;
}

std::string Transition::get_readSymbol(){
  return readTape_;
}

std::string Transition::get_writeSymbol(){
  return writeTape_;
}

std::string Transition::get_movement(){
  return movement_;
}

std::string Transition::get_next(){
  return nextState_;
}

void Transition::set_actual(std::string actual){
  actualState_ = actual;
}

void Transition::set_writeSymbol(std::string write){
  writeTape_ = write;
}

void Transition::set_readSymbol(std::string read){
  readTape_ = read;
}

void Transition::set_next(std::string next){
  nextState_ = next;
}

void Transition::set_movement(std::string move){
  movement_ = move;
}

void Transition::write(void){
  std::cout << actualState_ << " " << readTape_ << " " << nextState_ << " " << 
    writeTape_ << " " << movement_ << "\n";
}