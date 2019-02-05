cmake_minimum_required(VERSION 3.3)
project(Geometry_Calculations)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${GEOMETRY_CALCULATIONS_SOURCE_DIR}/cmake")
set(BIN_DIR ${GEOMETRY_CALCULATIONS_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/Geometry_Calculations)
add_executable(Geometry_Calculations src/main.cc)

install (TARGETS Geometry_Calculations RUNTIME DESTINATION ${BIN_DIR})