cmake_minimum_required(VERSION 3.3)
project(Pound_Conversion)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${POUND_CONVERSION_SOURCE_DIR}/cmake")
set(BIN_DIR ${POUND_CONVERSION_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/Pound_Conversion)
add_executable(Pound_Conversion src/main.cc)

install (TARGETS Pound_Conversion RUNTIME DESTINATION ${BIN_DIR})