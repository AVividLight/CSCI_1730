cmake_minimum_required(VERSION 3.3)
project(DynArray)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${DYNARRAY_SOURCE_DIR}/cmake")
set(BIN_DIR ${DYNARRAY_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/DynArray)
add_executable(DynArray src/main.cc)

install (TARGETS DynArray RUNTIME DESTINATION ${BIN_DIR})