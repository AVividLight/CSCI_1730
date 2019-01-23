cmake_minimum_required(VERSION 3.3)
project(Fibonacci_Sequence)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${FIBONACCI_SEQUENCE_SOURCE_DIR}/cmake")
set(BIN_DIR ${FIBONACCI_SEQUENCE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/Fibonacci_Sequence)
add_executable(Fibonacci_Sequence src/main.cc)

install (TARGETS Fibonacci_Sequence RUNTIME DESTINATION ${BIN_DIR})