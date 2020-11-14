#pragma once
#include <iostream>
#include <vector>

class Transition{
  private:
    std::string actualState_;              //estado incial
    std::string readTape_;             //simbolo que consume
    std::string writeTape_;                 //simbolo del top de la pila
    std::string nextState_;                //estado siguiente
    std::string movement_;
    int tapeNumber_;

    std::vector<std::string> readTapes_;
    std::vector<std::string> writeTapes_;
    std::vector<std::string> movements_;
  
  public:
    Transition(){};
    Transition(int notValid);
    Transition(std::string aux, int number);
    std::string get_actual();              //getter del estado inicial
    std::string get_readSymbol();                 //get del simbolo a leer de la cinta
    std::string get_writeSymbol(); //getter del simbolo a leer de la cinta
    std::string get_next();                //getter del estado siguiente
    std::string get_movement();              //getter del movimiento

    void set_actual(std::string actual);              //setter del estado incial
    void set_writeSymbol(std::string write);                    //setter del simbolo a escribir en la cintas
    void set_readSymbol(std::string read); //setter del simbolo a leer de la cinta
    void set_next(std::string next);                  //setter del estado siguiente
    void set_movement(char move);        //setter del movimiento
    void write();                                     //imprimir en pantalla

    std::vector<std::string> get_readSymbols(void);
    std::vector<std::string> get_writeSymbols(void);
    std::vector<std::string> get_movements(void);
};