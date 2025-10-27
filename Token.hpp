// -*- C++17 -*-  

#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

#include <iostream>
#include <string>
#include <variant>



enum TokenType {
  // Single-character tokens.
  LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
  COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

  // One or two character tokens.
  BANG, BANG_EQUAL,
  EQUAL, EQUAL_EQUAL,
  GREATER, GREATER_EQUAL,
  LESS, LESS_EQUAL,

  // Literals.
  IDENTIFIER, STRING, NUMBER,

  // Keywords.
  AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
  PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

  END_OF_FILE 
};



class Token{
    public:
    TokenType token;
    std::string lexeme;

    //literal
    double numberValue;
    std::string stringValue;
    bool boolValue;

    int line;

    Token(TokenType token, std::string lexeme, double num, int line)
            : token(token), lexeme(lexeme), numberValue(num), stringValue(""), boolValue(false), line(line) {}


    std::string tostr() const {
        std::string value;
        if (!stringValue.empty()) value = stringValue;
        else if (numberValue != 0) value = std::to_string(numberValue);
        else value = boolValue ? "true" : "false";

        return std::to_string(token) + " " + lexeme + " " + value;
    }


};

#endif