set(${PROJECT_NAME}_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

set(HEADER_FILES
        ${${PROJECT_NAME}_INCLUDE_DIR}/minesweeper.h
        ${${PROJECT_NAME}_INCLUDE_DIR}/constants.h
        ${${PROJECT_NAME}_INCLUDE_DIR}/Board.h
        ${${PROJECT_NAME}_INCLUDE_DIR}/Tile.h
        ${${PROJECT_NAME}_INCLUDE_DIR}/Game.h)

set(SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/src/Board.cpp
        ${PROJECT_SOURCE_DIR}/src/Tile.cpp
        ${PROJECT_SOURCE_DIR}/src/Game.cpp)

add_library(minesweeper SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(minesweeper PUBLIC ${${PROJECT_NAME}_INCLUDE_DIR})

