cmake_minimum_required(VERSION 3.3)
project(Pure_Virtual_Shapes)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PURE_VIRTUAL_SHAPES_SOURCE_DIR}/cmake")
set(BIN_DIR ${PURE_VIRTUAL_SHAPES_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/Pure_Virtual_Shapes)
add_executable(Pure_Virtual_Shapes src/main.cc)

install (TARGETS Pure_Virtual_Shapes RUNTIME DESTINATION ${BIN_DIR})