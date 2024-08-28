#include <iostream>
#include "lexer.cpp"
#include "readfile.cpp"

int main() {
//    std::string sourceCode = "let x = 5; for(let i = 0; i < 5; i++) {};";
//    lexer(sourceCode);
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
    std::string filename = "/Users/ugurabbasov/Desktop/turboscript/source.tbs";
    std::string fileContent = readFile(filename);

    if (!fileContent.empty()) {
        std::cout << "File content:\n" << fileContent << std::endl;
    } else {
        std::cout << "File was empty or could not be read." << std::endl;
    }
    return 0;
}