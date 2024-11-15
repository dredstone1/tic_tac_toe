# project(TicTacToeLib)
#
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
# add_library(TicTacToeLib
#     src/Board.cpp
#     src/Board.hpp
#     src/BoardGrid.cpp
#     src/BoardGrid.hpp
#     src/game.cpp
# )
#
# # target_include_directories(TicTacToe
# #     PUBLIC
# #     ${CMAKE_CURRENT_SOURCE_DIR}/include
# # )
# #


cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

# Add the TicTacToe library
add_library(TicTacToe
    src/game.cpp
    src/Board.cpp
    src/BoardGrid.cpp
)

# Include directories for the TicTacToe library
target_include_directories(TicTacToe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# # Add the players library
# add_library(PlayerUiInterface
#     src/players/StandartPlayer.cpp
# )
#
# # Include directories for the PlayerUiInterface library
# target_include_directories(PlayerUiInterface PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
#
# # Link the players library to the TicTacToe library
# target_link_libraries(TicTacToe PUBLIC PlayerUiInterface)
