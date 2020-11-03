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

void Tape::set(std::string setString){
  std::string aux;
  tape_.push_back(".");
  for(int i = 0; i < setString.size(); i++){
    aux += setString[i];
    tape_.push_back(aux);
    aux = "";
  }
  tape_.push_back(".");

  head_ = 0;
}

void Tape::write(void){
  for(int i = 0 ; i < tape_.size(); i++){
    if(i == head_){
      std::cout << "[" << tape_[i] << "]";
    } else {
      std::cout << tape_[i];
    }
  }
  std::cout << "\n";
}