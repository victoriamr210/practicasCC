#include "../include/transition.hpp"
#include <vector>

Transition::Transition(std::string aux, int number) {
  tapeNumber_ = number;

  std::string insert, space = " ";
  int pos = 0;
  // std::cout << "seg\n";
  std::vector<std::string> to_insert;
  // std::cout << aux << "\n";

  while ((pos = aux.find(space)) != std::string::npos){
    insert = aux.substr(0, pos);
    to_insert.push_back(insert);
    aux.erase(0, pos + space.length());
  }
  to_insert.push_back(aux);
  // to_insert.push_back(aux);
  int last = 0;
  set_actual(to_insert[last++]);
  for(int i = 0; i< tapeNumber_; i++){
    readTapes_.push_back(to_insert[last++]);
    // std::cout << "read\n";

    // last++;
  }
  // set_readSymbol(to_insert[1]);
  set_next(to_insert[last++]);
  for(int i = 0; i < tapeNumber_; i++){
    writeTapes_.push_back(to_insert[last++]);
    // std::cout << "write\n";
  }
  for(int i = 0; i< tapeNumber_; i++){
    movements_.push_back(to_insert[last++]);
    // std::cout << "move\n";
  }
  // set_writeSymbol(to_insert[3]);
  // set_movement(to_insert[4]);
  // set_insert(stackInsert);
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

std::vector<std::string> Transition::get_readSymbols(void){
  return readTapes_;
}

std::vector<std::string>Transition:: get_writeSymbols(void){
  return writeTapes_;
}
std::vector<std::string> Transition::get_movements(void){
  return movements_;
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

void Transition::set_movement(char move){
  movement_ = move;
}

void Transition::write(void){
  // std::cout << actualState_ << " " << readTape_ << " " << nextState_ << " " << 
  //   writeTape_ << " " << movement_ << "\n";
  std::cout << "-------------------------\n";
  std::cout  << "Actual: " << actualState_ << " ";
  std::cout << "\nLeer:\n";
  for(int i = 0; i<tapeNumber_; i++){
    std::cout << "cinta " << i << ":" << readTapes_[i] << "\n";
  }
  std::cout << "Siguiente:" << nextState_ << " ";

  std::cout << "\n\nEscribe: \n";
  for(int i = 0; i<tapeNumber_; i++){
    std::cout << "cinta " << i << ":" << writeTapes_[i] << "\n";
  }

  std::cout << "\nSe mueve: \n";
  std::cout << movement_[0];
  for(int i = 0; i<tapeNumber_; i++){
    std::cout << "cinta " << i << ":" << movements_[i] << " ";
  }
  std::cout << "\n-------------------------\n";
}