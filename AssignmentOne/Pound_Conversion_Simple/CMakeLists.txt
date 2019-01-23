cmake_minimum_required(VERSION 3.3)
project(Pound_Conversion_Simple)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${POUND_CONVERSION_SIMPLE_SOURCE_DIR}/cmake")
set(BIN_DIR ${POUND_CONVERSION_SIMPLE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/Pound_Conversion_Simple)
add_executable(Pound_Conversion_Simple src/main.cc)

install (TARGETS Pound_Conversion_Simple RUNTIME DESTINATION ${BIN_DIR})