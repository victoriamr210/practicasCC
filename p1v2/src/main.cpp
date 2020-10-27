#include <iostream>
#include <fstream>
#include <vector>
#include "../include/APVs.hpp"

std::vector<std::string> get_strings(char file[]){
  std::fstream f;
  f.open(file);
  std::string aux;
  std::vector<std::string> strings;
  if(f.is_open()){
    while(std::getline(f, aux)){
      strings.push_back(aux);
    }
    return strings;
  } else {
    std::cout << "Error de apertura\n";
  }
}


int main(int argc, char* argv[]) {    
	if(argc == 3) {
    APV automata(argv[1]);
    std::vector<std::string> strings;
    if(automata.check_automaton()){
      automata.write();
      strings = get_strings(argv[2]);
      for(int i = 0; i < strings.size(); i++){
        try{
          automata.set_string(strings[i]);
          automata.write_string();
          automata.begin();
        }catch(char const* e){
          std::cout << e;
        }
      }
    }
    // automata.write();
  } else {
    std::cerr << "ERROR: Introduzca nombre de fichero pls\n";
  }
}