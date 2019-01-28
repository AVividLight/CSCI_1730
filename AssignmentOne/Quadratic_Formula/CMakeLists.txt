cmake_minimum_required(VERSION 3.3)
project(Quadratic_Formula)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${QUADRATIC_FORMULA_SOURCE_DIR}/cmake")
set(BIN_DIR ${QUADRATIC_FORMULA_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/Quadratic_Formula)
add_executable(Quadratic_Formula src/main.cc)

install (TARGETS Quadratic_Formula RUNTIME DESTINATION ${BIN_DIR})