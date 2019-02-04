cmake_minimum_required(VERSION 3.3)
project(Euclids_GCD_Method)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${EUCLIDS_GCD_METHOD_SOURCE_DIR}/cmake")
set(BIN_DIR ${EUCLIDS_GCD_METHOD_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/Euclids_GCD_Method)
add_executable(Euclids_GCD_Method src/main.cc)

install (TARGETS Euclids_GCD_Method RUNTIME DESTINATION ${BIN_DIR})