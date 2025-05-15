cmake_minimum_required(VERSION 3.10)
project(AiPlayer)

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

add_library(
  AiPlayer STATIC
  src/AiPlayer.cpp
  src/model/AiModel.cpp
  src/model/model.cpp
  src/trainer/trainer.cpp
  src/trainer/database/dataBase.cpp
  src/model/activations.cpp
  src/trainer/backPropagation.cpp
  src/model/neuralNetwork.cpp
  src/trainer/gradient.cpp
  src/model/LayerParameters.cpp
  src/model/neuron.cpp
  src/model/Layers/Hidden_Layer.cpp
  src/model/Layers/layer.cpp
  src/model/Layers/Output_Layer.cpp
  src/visualizer/VisualizerRenderer.cpp
  src/visualizer/VisualizerController.cpp
  src/visualizer/visualNN.cpp
  src/visualizer/visualL.cpp
  )

add_subdirectory(matplotplusplus)

target_link_libraries(AiPlayer TicTacToe matplot sfml-graphics sfml-window sfml-system)

target_include_directories(AiPlayer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
