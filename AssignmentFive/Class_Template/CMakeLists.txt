cmake_minimum_required(VERSION 3.3)
project(Class_Template)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CLASS_TEMPLATE_SOURCE_DIR}/cmake")
set(BIN_DIR ${CLASS_TEMPLATE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/Class_Template)
add_executable(Class_Template src/main.cc)

install (TARGETS Class_Template RUNTIME DESTINATION ${BIN_DIR})