cmake_minimum_required(VERSION 3.3)
project(Recursive_Fibonacci)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${RECURSIVE_FIBONACCI_SOURCE_DIR}/cmake")
set(BIN_DIR ${RECURSIVE_FIBONACCI_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/Recursive_Fibonacci)
add_executable(Recursive_Fibonacci src/main.cc)

install (TARGETS Recursive_Fibonacci RUNTIME DESTINATION ${BIN_DIR})