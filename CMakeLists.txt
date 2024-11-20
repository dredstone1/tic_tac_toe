cmake_minimum_required(VERSION 3.10)
project(TicTacToeGame)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(TicTacToeGame main.cpp)

add_subdirectory(library/TicTacToe)
add_subdirectory(library/StandartPlayer)

target_link_libraries(TicTacToeGame TicTacToe StandartPlayer)

