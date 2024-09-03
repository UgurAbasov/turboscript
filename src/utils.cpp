#include "utils.h"

#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

std::string readFile(std::string_view file_name) {
  std::string content = "";
  std::string line = std::string();

  std::ifstream file((std::string(file_name)));

  if (!file || file.bad()) {
    std::cerr << "Error: Could not open file " << file_name << std::endl;
    return content;
  }

  if (file.is_open()) {
    while (std::getline(file, line)) {
      content += line + "\n";
    }

    file.close();
  }

  return content;
}
