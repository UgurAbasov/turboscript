#ifndef TOKENS_H
#define TOKENS_H

#include <string>

typedef enum {
    KEYWORD,
    IDENTIFIER,
    NUMBER,
    OPERATOR,
    PUNCTUATION,
    WHITESPACE,
    UNKNOWN,
    EOF_TOKEN
} TokenType;

typedef struct {
    TokenType type;
    std::string value;
} Token;

#endif