cmake_minimum_required(VERSION 3.28)
project(AiPlayer)

include(FetchContent)

FetchContent_Declare(
    NeuralNetwork
    GIT_REPOSITORY https://github.com/dredstone1/NeuralNetwork.git
    GIT_TAG main
    GIT_SHALLOW ON
)

FetchContent_MakeAvailable(NeuralNetwork)

add_library(AiPlayer STATIC
  src/AiPlayer.cpp
)

target_link_libraries(AiPlayer TicTacToe NeuralNetwork)

target_include_directories(AiPlayer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
