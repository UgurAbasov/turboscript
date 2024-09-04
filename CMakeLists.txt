cmake_minimum_required(VERSION 3.27)
project(turboscript)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

# Project:
project(
  turboscript
  VERSION 0.0.1
  LANGUAGES CXX)

# Declarations:
set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(EXECUTABLE_NAME turboscript)

# Executable:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(${EXECUTABLE_NAME})

# Sub directories:
add_subdirectory(${SOURCE_DIR})
include_directories(${SOURCE_DIR})
