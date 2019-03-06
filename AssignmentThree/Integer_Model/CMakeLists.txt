cmake_minimum_required(VERSION 3.3)
project(Integer_Model)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${INTEGER_MODEL_SOURCE_DIR}/cmake")
set(BIN_DIR ${INTEGER_MODEL_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/Integer_Model)
add_executable(Integer_Model src/main.cc)

install (TARGETS Integer_Model RUNTIME DESTINATION ${BIN_DIR})