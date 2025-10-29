// -*- C++17 -*-  

#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

#include <iostream>
#include <string>
#include <variant>



enum TokenType {
  LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
  COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

  BANG, BANG_EQUAL,
  EQUAL, EQUAL_EQUAL,
  GREATER, GREATER_EQUAL,
  LESS, LESS_EQUAL,

  IDENTIFIER, STRING, NUMBER,

  AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
  PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

  END_OF_FILE 
};



class Token{
    public:
    //type of the lexeme
    TokenType token;


    std::string lexeme;

    // convert that textual representation of a value to the living runtime object 
    //that will be used by the interpreter later.
    double numberValue;
    std::string stringValue;
    bool boolValue;

    //location
    int line;

    Token(TokenType token, std::string lexeme, double num, int line);
    std::string tostr() const;


};

#endif