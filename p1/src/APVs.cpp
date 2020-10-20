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
      trans.push(t);
    }
    // std::cout << initialState << " " << initialStack;

    f.close();
    if(check_automaton()) {
      set_string(file2);
      std::cout << "Success!!!\n";
      write();
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
  std::cout << "\nEstados: ";
  for(auto i = states.begin(); i != states.end(); i++){
    std::cout << *i << " ";
  }
  std::cout <<"\n";

  std::cout << "Alfabeto: ";
  for(auto i = symbols.begin(); i != symbols.end(); i++){
    std::cout << *i << " ";
  }
  std::cout <<"\n";

  std::cout << "Alfabeto pila: ";
  for(auto i = stackSymb.begin(); i != stackSymb.end(); i++){
    std::cout << *i << " ";
  }
  std::cout <<"\n";

  std::cout << "Estado inicial: " << initialState << "\n";
  std::cout << "Top de la pila: " << initialStack << "\n";

  std::cout << "Transiciones:\n";

  trans.write();
}

void APV::begin () {
  pila.push(initialStack);
  trans.start();
  std::string aux;
  std::vector<transition> v;
  std::stack<std::string> p = pila;

  run(initialState, checkString, p);
  //for(cadena i ){
  //   vector transitions
  //   if(vectro,size > 0)
  //   for(vector ){

  //     nextstate cadena[i]
  //   }
  // }
}

void APV::run(std::string currentState, std::string testString, std::stack<std::string> p){
  std::cout << "String: ";
  std::cout << testString;
  if(testString.size() == 0 && p.empty()){
    std::cout << "Cadena no aceptada\n";
    return;
  }else{
    std::string auxSymbol;
    std::cout << "\n--else\n";

    auxSymbol += testString[0];
    std::vector<transition> v = trans.get_transitions(auxSymbol, p.top(), currentState);
    std::cout << "Candidatos: \n";
    for(int i = 0; i < v.size(); i++){
      v[i].write();
    }
    if(v.size() == 0){
      std::cout << "Cadena aceptada\n";
      return;
    } 
    for(int i = 0; i < v.size(); i++){
      if(v[i].get_symbol() != ".") {
        testString.erase(testString.begin());
      } 
      std::stack<std::string> auxStack = copyStack(p, v[i].get_insert());
      std::cout << testString;
      std::cout << "\n\n";
      run (v[i].get_next(), testString, auxStack);
    }

  }
}

void APV::set_string(char file[]){
  std::fstream f;
  f.open(file);
  f >> checkString;
  std::cout << checkString << "\n";
}

std::stack<std::string> APV::copyStack(std::stack<std::string> p, std::vector<std::string> insert){
  p.pop();
  for(int i = 0; i < insert.size(); i++){
    if(insert[i] != "."){
      p.push(insert[i]);
    }
  }
  return p;
}