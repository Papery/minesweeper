cmake_minimum_required(VERSION 3.10)
project(minesweeper)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)
add_subdirectory(test)

add_executable(Minesweeper main.cpp)
target_link_libraries(Minesweeper minesweeper)


