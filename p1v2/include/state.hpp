#pragma once
#include <iostream>
#include <vector>
#include "transition.hpp"

class state{
  private:
    std::string id;  //identificador del estado
    std::vector<transition> trans; //conjutno de transiones del estado


  public:
    state(std::string state);  //constructor

    std::string get_id(void);  //getter del identificador

    bool check_id(std::string aux);  // compara identificadroes de estado
    //transiciones posibles segun el simbolo a consumir y simbolo en el top de la pila
    std::vector<transition> get_trans(std::string symbol, std::string topStack); 
    void push(transition t);  //añadir transicion al estado
    void write(void); //imprimir en pantallaa el estado y sus transiciones
};
