cmake_minimum_required(VERSION 3.3)
project(String_Statistics)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${STRING_STATISTICS_SOURCE_DIR}/cmake")
set(BIN_DIR ${STRING_STATISTICS_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/String_Statistics)
add_executable(String_Statistics src/main.cc)

install (TARGETS String_Statistics RUNTIME DESTINATION ${BIN_DIR})