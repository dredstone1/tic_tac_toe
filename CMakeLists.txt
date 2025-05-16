cmake_minimum_required(VERSION 3.10)
project(TicTacToeGame)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(RESOURCE_DIR "${CMAKE_SOURCE_DIR}/resources/fonts")

add_executable(TicTacToeGame main.cpp)

add_subdirectory(library/TicTacToe)
add_subdirectory(library/StandardPlayer)
add_subdirectory(library/AiPlayer)

add_compile_definitions(RESOURCE_DIR="${RESOURCE_DIR}")
target_link_libraries(TicTacToeGame TicTacToe StandardPlayer AiPlayer)
