#pragma once
#include <iostream>
#include <vector>
#include <string>

class transition{
  private:
    std::string actualState;  //estado incial
    std::string stringSymbol; //simbolo que consume
    std::string topStack; //simbolo del top de la pila
    std::vector<std::string> insertStack; //simbolos a insertar en la pila
    std::string nextState; //estado siguiente
  
  public:
    transition(){}
    transition(std::string aux); //constructro dado una string con todos los atributos
    transition(std::string actual, char symbol, std::string top, std::vector<std::string> insert, std::string next);
    std::string get_actual(); //getter del estado inicial
    std::string get_top();  //get del simbolo del top de la pila
    std::vector<std::string> get_insert(); //getter de los simbolos a insertar en al pila
    std::string get_next();  //getter del estado siguiente
    std::string get_symbol();  //getter del simbolo consumido

    void set_actual(std::string actual); //setter del estado incial
    void set_top(std::string top); //setter del simbolo del top de la pila
    void set_insert(std::vector<std::string> insert);  //setter de los simbolos a insertar a la pila
    void set_next(std::string next);  //setter del estado siguiente
    void set_symbol(std::string stringSymbol); //setter del simbolo a consumir
    void write(); //imprimir en pantalla
};