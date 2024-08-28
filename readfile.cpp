#include <iostream>
#include <fstream>
#include <string>

std::string readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return "";
    }

    std::string content;
    std::string line;
    while (std::getline(file, line)) {
        content += line + "\n";
    }

    if (file.bad()) {
        std::cerr << "Error: An error occurred while reading the file" << std::endl;
        return "";
    }

    file.close();
    return content;
}