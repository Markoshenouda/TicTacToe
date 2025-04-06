cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5 REQUIRED Widgets)

include_directories(include)

set(SOURCES
    src/GameLogic.cpp
    src/AI.cpp
    src/UserManager.cpp
    src/GameWindow.cpp
    src/main.cpp
)

add_executable(TicTacToe ${SOURCES})

target_link_libraries(TicTacToe Qt5::Widgets)
