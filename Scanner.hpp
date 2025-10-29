#ifndef SCANNER_H
#define SCANNER_H

#include <iostream>
#include <string>
#include <variant>
#include <vector>
#include "Token.hpp"



class Scanner {
  private:
    std::string source;
    std::vector<Token> tokens;
    int start = 0;
    int current = 0;
    int line = 0;

  public:
    Scanner(std::string);
    std::vector<Token> scanTokens();
    void scanToken();
};

#endif