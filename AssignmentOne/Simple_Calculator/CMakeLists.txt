cmake_minimum_required(VERSION 3.3)
project(Simple_Calculator)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${SIMPLE_CALCULATOR_SOURCE_DIR}/cmake")
set(BIN_DIR ${SIMPLE_CALCULATOR_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/Simple_Calculator)
add_executable(Simple_Calculator src/main.cc)

install (TARGETS Simple_Calculator RUNTIME DESTINATION ${BIN_DIR})