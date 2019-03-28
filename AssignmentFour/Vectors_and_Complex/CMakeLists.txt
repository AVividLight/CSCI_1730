cmake_minimum_required(VERSION 3.3)
project(Vectors_and_Complex)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${VECTORS_AND_COMPLEX_SOURCE_DIR}/cmake")
set(BIN_DIR ${VECTORS_AND_COMPLEX_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/Vectors_and_Complex)
add_executable(Vectors_and_Complex src/main.cc)

install (TARGETS Vectors_and_Complex RUNTIME DESTINATION ${BIN_DIR})