#include "../include/APVs.hpp"
#include <fstream>
#include <string>
#include <algorithm> 

APV::APV(char file1[], char file2[]){
  read(file1, file2);
}

void APV::read(char file1[], char file2[]){
  std::fstream f;
  f.open(file1);
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
      trans.push_back(t);
    }
    // std::cout << initialState << " " << initialStack;

    f.close();
    if(check_automaton()) {
      set_string(file2);
      begin();
    }

  }else{
    std::cerr << "Error de apertura\n";
  }
  
}

void APV::build_states(std::string aux){
  std::string toInsert = "";
  for(int i = 0; i < aux.size(); i++){
    if(aux[i] != ' '){
      toInsert += aux[i];
    } else {
      states.insert(toInsert);
      toInsert = "";
    }
  }
  states.insert(toInsert);
  // write();
}

void APV::build_symbols(std::string aux){
  std::string toInsert = "";
  for(int i = 0; i < aux.size(); i++){
    if(aux[i] != ' '){
      toInsert = aux[i];
      // std::cout << insert << " insert\n";
      symbols.insert(toInsert);
      // std::cout << symbols.back() << " back\n";
    }
  }
  // write();
}

void APV::build_stack_symbols(std::string aux){
  std::string toInsert = "";
  for(int i = 0; i < aux.size(); i++){
    if(aux[i] != ' '){
      toInsert = aux[i];
      stackSymb.insert(toInsert);
    }
  }
}

bool APV::check_automaton(void) {

  // write();

  if (states.find(initialState) == states.end()){
    std::cerr << "ERROR: Estado inicial no esta en el conjunto de estados\n";
    return false;
  }

  if (stackSymb.find(initialStack) == stackSymb.end()){
    std::cerr << "ERROR: Simbolo inicial de la pila no esta en el conjunto de simbolos\n";
    return false;
  }

  return true;
}


void APV::write(void) {
  // std::cout << states[0] << " ";

  for(auto i = states.begin(); i != states.end(); i++){
    std::cout << *i;
  }
  std::cout <<"\n";
}

void APV::begin () {
  std::cout << "Success!!!\n";
}

void APV::set_string(char file[]){
  std::fstream f;
  f.open(file);
  f >> checkString;
  std::cout << checkString << "\n";
}