cmake_minimum_required(VERSION 3.28)
project(AiPlayer)

add_library(
  AiPlayer STATIC
  src/AiPlayer.cpp
  )

  add_subdirectory(NeuralNetwork)

target_link_libraries(AiPlayer TicTacToe NeuralNetwork)

target_include_directories(AiPlayer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
