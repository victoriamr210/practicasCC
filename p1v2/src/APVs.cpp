#include "../include/APVs.hpp"
#include <fstream>
#include <string>
#include <algorithm> 

APV::APV(char file1[]){
  read(file1);
}

void APV::read(char file1[]){
  std::fstream f;
  f.open(file1);
  std::string aux;

  if(f.is_open()){
    while(std::getline(f, aux)){
      if(aux[0] != '#'){
        build_states(aux);
        break;
      }
    }
    std::getline(f,aux);
    build_symbols(aux);
    std::getline(f, aux);
    build_stack_symbols(aux);
    std::getline(f, initialState);
    std::getline(f, initialStack);

    while(!f.eof()){
      std::getline(f, aux);
      transition t(aux);
      make_state(t.get_actual(), t);
      // states.find()
      // trans.push(t);
    }

    f.close();

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
      state s(toInsert);
      states.push_back(s);
      stateSet.insert(toInsert);
      toInsert = "";
    }
  }
  state s(toInsert);
  states.push_back(s);
  stateSet.insert(toInsert);
  // write();
}

void APV::build_symbols(std::string aux){
  std::string toInsert = "";
  for(int i = 0; i < aux.size(); i++){
    if(aux[i] != ' '){
      toInsert = aux[i];
      symbols.insert(toInsert);
    }
  }
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

  if (stateSet.find(initialState) == stateSet.end()){
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
  for(auto i = stateSet.begin(); i != stateSet.end(); i++){
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

  std::cout << "\nTransiciones:\n";

  for(int i = 0; i < states.size(); i++){
    std::cout << "\n\tEstado " << states[i].get_id() << ":\n";
    
    states[i].write();
  }

}

void APV::write_string(void){
  std::cout << "\n\tCadena a comprobar: " << checkString << "\n";
}

void APV::begin () {
  pila.push(initialStack);
  // trans.start();
  std::string aux;
  std::vector<transition> v;
  std::stack<std::string> p = pila;

  run(initialState, checkString, p);
}



void APV::run(std::string currentState, std::string testString, std::stack<std::string> p){
  std::cout << "\n-----------------------------------\n";
  // std::cout << p.top();
  if(testString.size() == 0 && p.empty()){
      throw "Cadena aceptada\n";
    // std::cout << "Cadena no aceptada\n";
    // return;
  } else{
    // std::cout << "String size: " << testString << "\n";
    std::string auxSymbol;
    auxSymbol += testString[0];
    std::cout << "Simbolo actual: " << auxSymbol;
    std::cout << "\tEstado actual: " << currentState << "\n";
    // if(!p.empty()){
    std::vector<transition> v;
    if(p.empty()){
      v = get_transitions(auxSymbol, ".", currentState);
    } else {
      v = get_transitions(auxSymbol, p.top(), currentState);
    }
    std::cout << "\nTransiciones posibles: \n";
    for(int i = 0; i < v.size(); i++){
      v[i].write();
    }
    if(v.size() == 0){
      std::cout << "Cadena no aceptada\n";
      return;
    }
    for(int i = 0; i < v.size(); i++){
    std::string auxString = testString; 
      if(v[i].get_symbol() != ".") {
        auxString.erase(auxString.begin());
      }
      std::stack<std::string> auxStack = copyStack(p, v[i].get_insert());
      write_stack(auxStack);
      run(v[i].get_next(), auxString, auxStack);
      
    }
  } 
}

void APV::set_string(std::string aux){
  checkString = aux;
}

std::stack<std::string> APV::copyStack(std::stack<std::string> p, std::vector<std::string> insert){
  if(!p.empty()){
    p.pop();
  }
  // std::cout << "vector: ";
  // for(int i = 0; i < insert.size(); i++){
  //   std::cout << insert[i] << " ";
  // }
  // std::cout << "\n";
  for(int i = insert.size() -1; i >= 0; i--){
    if(insert[i] != "."){
      p.push(insert[i]);
    }
  }
  return p;
}

void APV::write_stack(std::stack<std::string>  p){
  std::cout << "Pila: \n";
  while (!p.empty()) {
    std::cout << p.top() << " ";
    p.pop();
  }
  std::cout <<"\n";
}

void APV::make_state(std::string s, transition t){
  for(int i = 0; i < states.size(); i++){
    if(states[i].check_id(s)){
      states[i].push(t);
    }
  }
}

std::vector<transition> APV::get_transitions(std::string symbol, std::string topStack, std::string state) {
  std::vector<transition> v;
  for(int i = 0; i < states.size(); i++){
    if(states[i].check_id(state)){
      v = states[i].get_trans(symbol, topStack);
      return v;
    }
  }
}