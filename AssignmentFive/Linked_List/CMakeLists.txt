cmake_minimum_required(VERSION 3.3)
project(Link_List)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${LINK_LIST_SOURCE_DIR}/cmake")
set(BIN_DIR ${LINK_LIST_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/Link_List)
add_executable(Link_List src/main.cc)

install (TARGETS Link_List RUNTIME DESTINATION ${BIN_DIR})