cmake_minimum_required(VERSION 3.10)
project(AiPlayer)

add_library(AiPlayer STATIC src/AiPlayer.cpp)

target_link_libraries(AiPlayer TicTacToe)

target_include_directories(AiPlayer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
