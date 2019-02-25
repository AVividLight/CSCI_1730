cmake_minimum_required(VERSION 3.3)
project(Elevator)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${ELEVATOR_SOURCE_DIR}/cmake")
set(BIN_DIR ${ELEVATOR_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/Elevator)
add_executable(Elevator src/main.cc)

install (TARGETS Elevator RUNTIME DESTINATION ${BIN_DIR})