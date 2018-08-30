cmake_minimum_required(VERSION 3.10)
project(minesweeper)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(minesweeper/)

set(SOURCE_FILES main.cpp)
add_executable(Minesweeper ${SOURCE_FILES})
target_link_libraries(Minesweeper minesweeper)


