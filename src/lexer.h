#ifndef SRC_LEXER_H_
#define SRC_LEXER_H_

#include <string>
#include <vector>

#include "tokens.h"

TokenType get_token_type(const std::string& value);
bool is_in_set(const std::string& value, const std::vector<std::string>& set);
void add_token(std::vector<Token>& tokens, TokenType type,
               const std::string& value);
void lexer(const std::string& sourceCode);

#endif  // SRC_LEXER_H_
