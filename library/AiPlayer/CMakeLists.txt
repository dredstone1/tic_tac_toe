cmake_minimum_required(VERSION 3.10)
project(AiPlayer)

add_library(
  AiPlayer STATIC
  src/AiPlayer.cpp
  src/model/AiModel.cpp
  src/model/layer.cpp
  src/model/model.cpp
  src/trainer/trainer.cpp
  src/trainer/database/dataBase.cpp
  src/model/ActivationFunctions.cpp
  src/trainer/backPropagation.cpp
  src/model/neuron.cpp
  src/model/neuralNetwork.cpp
  src/trainer/gradient.cpp)
add_subdirectory(matplotplusplus)

target_link_libraries(AiPlayer TicTacToe matplot)

target_include_directories(AiPlayer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
