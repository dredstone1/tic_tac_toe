# cmake_minimum_required(VERSION 3.28.3)
# project(TicTacToeGame)
#
# # Specify the C++ standard
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED True)
#
# add_subdirectory(library/TicTacToe)
#
# include_directories(${PROJECT_SOURCE_DIR}/library/TicTacToe/include)
# add_executable(${PROJECT_NAME} main.cpp) 
#
# target_link_libraries(${PROJECT_NAME} TicTacToe)


cmake_minimum_required(VERSION 3.10)
project(TicTacToeGame)

# Add the executable for the main application
add_executable(TicTacToeGame main.cpp)

# Include the TicTacToe package
add_subdirectory(library/TicTacToe)

# Link the TicTacToe library to the main application
target_link_libraries(TicTacToeGame TicTacToe)
