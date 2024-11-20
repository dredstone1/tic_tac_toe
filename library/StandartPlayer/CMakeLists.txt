cmake_minimum_required(VERSION 3.10)
project(StandartPlayer)

add_library(StandartPlayer STATIC src/StandartPlayer.cpp)

target_link_libraries(StandartPlayer TicTacToe)

target_include_directories(StandartPlayer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
