#pragma once
#include <iostream>

class state{
  private:
    std::string id;

  public:
    state(std::string aux){
      id = state;
    }

    std::string get_id(void){
      return id;
    }

    bool check_id(std::string aux){
      return id.compare(aux);
    }
};