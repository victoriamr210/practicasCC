#include "../include/APV.hpp"
#include <fstream>
#include <string>

APV::APV(char file[]){
  read(file);
}

void APV::read(char file[]){
  std::fstream f;
  f.open(file);
  std::string aux;

  if(f.is_open()){
    while(std::getline(f, aux)){
      if(aux[0] != '#'){
        std::cout << aux << "\n";
        build_states(aux);
        break;
      }
    }
    std::getline(f,aux);
    // std::cout << aux << "\n";
    build_symbols(aux);
    std::getline(f, aux);
    // std::cout << aux << "\n";
    build_stack_symbols(aux);
    std::getline(f, intialState);
    std::getline(f, initialStack);
    // f >> intialState;
    // f >> initialStack;

    while(!f.eof()){
      std::getline(f, aux);
      // std::cout << "AUX2-> " << aux << "\n";
      // std::cout << "transition->  ";
      transition t(aux);
    }
    // std::cout << intialState << " " << initialStack;


  }else{
    std::cerr << "Error de apertura\n";
  }
  f.close();
  
}

void APV::build_states(std::string aux){
  std::string insert = "";
  for(int i = 0; i < aux.size(); i++){
    if(aux[i] != ' '){
      insert+= aux[i];
    } else {
      states.push_back(insert);
      insert = "";
    }
  }
  states.push_back(insert);
}

void APV::build_symbols(std::string aux){
  std::string insert = "";
  for(int i = 0; i < aux.size(); i++){
    if(aux[i] != ' '){
      insert=aux[i];
      // std::cout << insert << " insert\n";
      symbols.push_back(insert);
      // std::cout << symbols.back() << " back\n";
    }
  }
  write();
}

void APV::build_stack_symbols(std::string aux){
  std::string insert = "";
  for(int i = 0; i < aux.size(); i++){
    if(aux[i] != ' '){
      insert=aux[i];
      stackSymb.push_back(insert);
    }
  }
}


void APV::write(void) {
  // std::cout << states[0] << " ";

  // for(int i = 0; i < states.size(); i++){
  //   std::cout << states[i] << " ";
  // }
  std::cout <<"\n";
}