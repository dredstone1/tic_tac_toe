cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

add_library(TicTacToe src/game.cpp src/Board.cpp src/BoardGrid.cpp
                      src/PlayerAdapter.cpp)

target_include_directories(TicTacToe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
