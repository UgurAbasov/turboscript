#include "lexer.h"

#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include "tokens.h"

const std::vector<std::string> keywords = {"let", "if", "else", "for", "while"};
const std::vector<std::string> operators = {"=", "+", "-", "*", "/"};
const std::vector<std::string> punctuations = {";", ",", "(", ")", "{", "}"};

bool is_in_set(const std::string& value, const std::vector<std::string>& set) {
  return std::find(set.begin(), set.end(), value) != set.end();
}

TokenType get_token_type(const std::string& value) {
  if (is_in_set(value, keywords)) {
    return KEYWORD;
  }
  if (is_in_set(value, operators)) {
    return OPERATOR;
  }
  if (is_in_set(value, punctuations)) {
    return PUNCTUATION;
  }
  return IDENTIFIER;
}

void add_token(std::vector<Token>& tokens, TokenType type,
               const std::string& value) {
  tokens.push_back({type, value});
}

void lexer(const std::string& sourceCode) {
  std::vector<Token> tokens;
  size_t i = 0;

  while (i < sourceCode.length()) {
    char char_at_i = sourceCode[i];

    if (isspace(char_at_i)) {
      i++;
      continue;
    }

    if (isalpha(char_at_i) || char_at_i == '_') {
      size_t start = i;
      while (isalnum(sourceCode[i]) || sourceCode[i] == '_') {
        i++;
      }
      std::string value = sourceCode.substr(start, i - start);
      TokenType type = get_token_type(value);
      add_token(tokens, type, value);
      continue;
    }

    if (isdigit(char_at_i)) {
      size_t start = i;
      while (isdigit(sourceCode[i])) {
        i++;
      }
      std::string value = sourceCode.substr(start, i - start);
      add_token(tokens, NUMBER, value);
      continue;
    }

    std::string value(1, char_at_i);
    if (is_in_set(value, operators)) {
      add_token(tokens, OPERATOR, value);
    } else if (is_in_set(value, punctuations)) {
      add_token(tokens, PUNCTUATION, value);
    } else {
      add_token(tokens, UNKNOWN, value);
    }
    i++;
  }

  add_token(tokens, EOF_TOKEN, "");

  for (const auto& token : tokens) {
    std::string type_str;
    switch (token.type) {
      case KEYWORD:
        type_str = "KEYWORD";
        break;
      case IDENTIFIER:
        type_str = "IDENTIFIER";
        break;
      case NUMBER:
        type_str = "NUMBER";
        break;
      case OPERATOR:
        type_str = "OPERATOR";
        break;
      case PUNCTUATION:
        type_str = "PUNCTUATION";
        break;
      case WHITESPACE:
        type_str = "WHITESPACE";
        break;
      case UNKNOWN:
        type_str = "UNKNOWN";
        break;
      case EOF_TOKEN:
        type_str = "EOF";
        break;
      default:
        type_str = "UNKNOWN";
        break;
    }
    std::cout << "Type: " << type_str << ", Value: '" << token.value << "'\n";
  }
}
