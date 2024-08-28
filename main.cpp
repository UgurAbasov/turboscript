#include <iostream>
#include "lexer.cpp"

int main() {
    std::string sourceCode = "let x = 5; for(let i = 0; i < 5; i++) {};";
    lexer(sourceCode);
    return 0;
}