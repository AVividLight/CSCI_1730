cmake_minimum_required(VERSION 3.3)
project(Square_Root_Approximator)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${SQUARE_ROOT_APPROXIMATOR_SOURCE_DIR}/cmake")
set(BIN_DIR ${SQUARE_ROOT_APPROXIMATOR_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/Square_Root_Approximator)
add_executable(Square_Root_Approximator src/main.cc)

install (TARGETS Square_Root_Approximator RUNTIME DESTINATION ${BIN_DIR})