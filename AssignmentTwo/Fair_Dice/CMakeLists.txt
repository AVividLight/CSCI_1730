cmake_minimum_required(VERSION 3.3)
project(Fair_Dice)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${FAIR_DICE_SOURCE_DIR}/cmake")
set(BIN_DIR ${FAIR_DICE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include/Fair_Dice)
add_executable(Fair_Dice src/main.cc)

install (TARGETS Fair_Dice RUNTIME DESTINATION ${BIN_DIR})