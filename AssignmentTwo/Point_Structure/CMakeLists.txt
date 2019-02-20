cmake_minimum_required(VERSION 3.3)
project(Point_Structure)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${POINT_STRUCTURE_SOURCE_DIR}/cmake")
set(BIN_DIR ${POINT_STRUCTURE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/Point_Structure)
add_executable(Point_Structure src/main.cc)

install (TARGETS Point_Structure RUNTIME DESTINATION ${BIN_DIR})