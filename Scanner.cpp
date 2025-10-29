#include "Scanner.hpp"
#include "Token.hpp"

#include <iostream>
#include <string>




Scanner::Scanner(std::string m_source) : source(m_source) {}


std::vector<Token> Scanner::scanTokens() {
    while (current<source.size()) {
      // We are at the beginning of the next lexeme.
      start = current;
      scanToken();
    }

    tokens.push_back(Token(TokenType::END_OF_FILE, "", 0, line));
    return tokens;
  }