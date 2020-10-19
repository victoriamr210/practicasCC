#include "../include/APV.hpp"
#include <fstream>
#include <string>
#include <algorithm> 

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
        // std::cout << aux << "\n";
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
    std::getline(f, initialState);
    std::getline(f, initialStack);
    // f >> initialState;
    // f >> initialStack;

    while(!f.eof()){
      std::getline(f, aux);
      // std::cout << "AUX2-> " << aux << "\n";
      // std::cout << "transition->  ";
      transition t(aux);
    }
    // std::cout << initialState << " " << initialStack;

    f.close();
    if(check_automaton()) {
      begin();
    }

  }else{
    std::cerr << "Error de apertura\n";
  }
  
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
  write();
  // std::string hola = states[0];
  //  for(int i = 0; i < states.size(); i++){
  // }
  // if(states[0] == "q1")
  //   std::cout << "bruh  super fuerte\n" ;
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
  // write();
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

bool APV::check_automaton(void) {
  // std::cout << initialState << "\n";
  // if(initialState.compare("q2")){
  //   std::cout << "bruh\n";
  // }
  std::cout << states[1] << " size\n";
  for(int i = 0; i < states.size(); i++){
    std::cout << states[i];
    if (initialState.compare(states[i]) == 0)
      std::cout << "bruh  super fuerte\n";
  }
  // write();
  if (std::find(states.begin(), states.end(), initialState) == states.end()){
    std::cerr << "ERROR: Estado inicial no esta en el conjunto de estados\n";
    return false;
  }

  if (std::find(stackSymb.begin(), stackSymb.end(), initialStack) == stackSymb.end()){
    std::cerr << "ERROR: SImbolo inicial de la pila no esta en el conjunto de simbolos\n";
    return false;
  }

  return true;
}


void APV::write(void) {
  // std::cout << states[0] << " ";

  for(int i = 0; i < states.size(); i++){
    std::cout << states[i];
  }
  std::cout <<"\n";
}

// std::vector<std::string> split(std::string aux){

// }