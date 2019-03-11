cmake_minimum_required(VERSION 3.3)
project(Complex_Class)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${COMPLEX_CLASS_SOURCE_DIR}/cmake")
set(BIN_DIR ${COMPLEX_CLASS_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/Complex_Class)
add_executable(Complex_Class src/main.cc)

install (TARGETS Complex_Class RUNTIME DESTINATION ${BIN_DIR})