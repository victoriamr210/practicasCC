#pragma once
#include <iostream>
#include <vector>
#define LEFT "L"
#define RIGHT "R"

class Tape{
  private:
    std::vector<std::string> tape_;
    int head_;
  
  public:
    Tape(){}
    Tape(std::string testString);
    void move_head(std::string write, std::string movement);
    std::string get_actual(void);
    int get_head(void);
    void set(std::string setString);
    void write(void);
};