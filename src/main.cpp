#include <iostream>
#include <string>

#include "utils.h"

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "No file was given! Exiting..." << std::endl;
    return 1;
  }

  std::string file_name = argv[1];
  std::string file_content = readFile(file_name);

  if (!file_content.empty()) {
    std::cout << "File content:\n" << file_content;
  }

  return 0;
}
