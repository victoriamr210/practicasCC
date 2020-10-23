#pragma once
#include <iostream>
#include <stack>
#include <set>
#include <string>
#include "transition.hpp"
#include "state.hpp"

class APV{
  private:
    std::stack<std::string> pila; //pila de simbolos
    std::set<std::string> stateSet; //conjunto Q
    std::vector<state> states; //estados con sus transiciones correspondientes
    std::set<std::string> symbols; //conjunto de simbolos
    std::set<std::string> stackSymb; //conjunto de simbolos de la pila
    std::string initialState; //estado incial
    std::string initialStack; //conjunto inicial de la pila
    std::string checkString; //cadena a comprobar
  
  public:
    APV(char file1[]); //constructor
    void read(char file1[]); //leer el fichero
    void write(); //imprimir automata
    void build_states(std::string aux); //crear conjunto de estados
    void build_symbols(std::string aux); //crear conjunto de simbolos
    void build_stack_symbols(std::string aux); //crear conjunto de simbolos de la pila

    bool check_automaton(void); //comprobar si el automata es valido
    void begin(void); //inicializar automata
    void run(std::string currentState, std::string testString, std::stack<std::string> p);  //funcion recursiva que realiza la traza
    std::stack<std::string> copyStack(std::stack<std::string> p, std::vector<std::string> insert);

    void set_string(std::string aux);  //cambiar cadena a comprobar
    void write_stack(std::stack<std::string> p); //mostrar pila
    void make_state(std::string s, transition t);  //crear estado con transiciones
    //transiciones posibles segun el esatado actual, el simbolo a consumir y simbolo en el top de la pila
    std::vector<transition> get_transitions(std::string symbol, std::string topStack, std::string state); 
};