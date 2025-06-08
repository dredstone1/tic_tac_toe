cmake_minimum_required(VERSION 3.28)
project(StandardPlayer)

add_library(StandardPlayer STATIC src/StandardPlayer.cpp)

target_link_libraries(StandardPlayer TicTacToe)

target_include_directories(StandardPlayer
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
