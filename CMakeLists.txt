cmake_minimum_required(VERSION 3.28)
project(TicTacToeGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(SANITIZER_FLAGS "-fsanitize=address -fno-omit-frame-pointer")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SANITIZER_FLAGS}")
set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} ${SANITIZER_FLAGS}")

add_executable(TicTacToeGame main.cpp)

add_subdirectory(library/TicTacToe)
add_subdirectory(library/StandardPlayer)
add_subdirectory(library/AiPlayer)

target_link_libraries(TicTacToeGame TicTacToe StandardPlayer AiPlayer)
