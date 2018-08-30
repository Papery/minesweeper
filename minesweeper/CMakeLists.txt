project(minesweeper)

set(minesweeper_SOURCE_FILES
        src/Board.cpp)

set(minesweeper_HEADER_FILES
        include/minesweeper.h
        include/Board.h)

add_library(minesweeper ${minesweeper_HEADER_FILES} ${minesweeper_SOURCE_FILES})

target_include_directories(minesweeper
        PUBLIC include
        PRIVATE src)

