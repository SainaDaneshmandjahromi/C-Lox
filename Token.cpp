#include "Token.hpp"

#include <iostream>
#include <string>

Token::Token(TokenType token, std::string lexeme, double num, int line)
        : token(token), lexeme(lexeme), numberValue(num), stringValue(""), boolValue(false), line(line) {}


std::string Token::tostr() const {
    std::string value;
    if (!stringValue.empty()) value = stringValue;
    else if (numberValue != 0) value = std::to_string(numberValue);
    else value = boolValue ? "true" : "false";

    return std::to_string(token) + " " + lexeme + " " + value;
}


