cmake_minimum_required(VERSION 3.3)
project(Modified_Calculator)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${MODIFIED_CALCULATOR_SOURCE_DIR}/cmake")
set(BIN_DIR ${MODIFIED_CALCULATOR_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/Modified_Calculator)
add_executable(Modified_Calculator src/main.cc)

install (TARGETS Modified_Calculator RUNTIME DESTINATION ${BIN_DIR})