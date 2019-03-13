cmake_minimum_required(VERSION 3.3)
project(Email_Validation)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${EMAIL_VALIDATION_SOURCE_DIR}/cmake")
set(BIN_DIR ${EMAIL_VALIDATION_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/Email_Validation)
add_executable(Email_Validation src/main.cc)

install (TARGETS Email_Validation RUNTIME DESTINATION ${BIN_DIR})