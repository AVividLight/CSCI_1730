cmake_minimum_required(VERSION 3.3)
project(Rock_Paper_Scissors)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${ROCK_PAPER_SCISSORS_SOURCE_DIR}/cmake")
set(BIN_DIR ${ROCK_PAPER_SCISSORS_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/Rock_Paper_Scissors)
add_executable(Rock_Paper_Scissors src/main.cc)

install (TARGETS Rock_Paper_Scissors RUNTIME DESTINATION ${BIN_DIR})