cmake_minimum_required(VERSION 3.3)
project(Text_File_Analytics)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${TEXT_FILE_ANALYTICS_SOURCE_DIR}/cmake")
set(BIN_DIR ${TEXT_FILE_ANALYTICS_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/Text_File_Analytics)
add_executable(Text_File_Analytics src/main.cc)

install (TARGETS Text_File_Analytics RUNTIME DESTINATION ${BIN_DIR})