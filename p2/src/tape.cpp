#include "../include/tape.hpp"
#include <algorithm>
#include <iterator>

Tape::Tape(void){
  tape_.push_back(".");
  head_ = 0;
}

Tape::Tape(std::string testString){
  std::string aux;
  tape_.push_back(".");
  for(int i = 0; i < testString.size(); i++){
    aux += testString[i];
    tape_.push_back(aux);
    aux = "";
  }
  tape_.push_back(".");

  head_ = 1;
}

void Tape::move_head(std::string write, std::string movement){
  tape_[head_] = write;
  char move = movement[0];
  if(movement == LEFT){
    head_--;
    if(head_ == -1){
      std::vector<std::string> aux = tape_;
      // tape_.resize(tape_.size() + 1);
      // tape_.insert(tape_.begin()+1, aux.begin(), aux.end());

      // tape_.reserve(v.size() + 6);

      // v.push_back(12);
      // v.push_back();
      // ...
    std::rotate(tape_.begin(), tape_.end() - 1, tape_.end());
    tape_.push_back(".");
    std::rotate(tape_.begin(), tape_.end() - 1, tape_.end());
    // tape_[0] == ".";
    // std::rotate(v.begin() + 1, v.begin() + 4, v.end());
    head_ = 0;
    }
  }
  if(movement == RIGHT){
    head_++;
    if(head_ == tape_.size()){
      tape_.resize(tape_.size() +1);
      tape_[head_] = ".";
    }
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