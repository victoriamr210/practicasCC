#include "../include/tape.hpp"

Tape::Tape(std::string testString){
  std::string aux;
  tape_.push_back(".");
  for(int i = 0; i < testString.size(); i++){
    aux += testString[i];
    tape_.push_back(aux);
    aux = "";
  }
  tape_.push_back(".");

  head_ = 0;
}

void Tape::move_head(std::string write, std::string movement){
  tape_[head_] = write;
  if(movement == LEFT){
    head_--;
  }
  if(movement == RIGHT){
    head_++;
  }
}

std::string Tape::get_actual(void){
  return tape_[head_];
}

int Tape::get_head(void){
  return head_;
}