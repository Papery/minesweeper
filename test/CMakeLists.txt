#include_directories(${GTEST_SOURCE_DIR}/include ${GTEST_SOURCE_DIR})

add_subdirectory(lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include)

set(UNIT_TESTS
        testEntry)

set(UNIT_TEST_LIBS gtest_main minesweeper)

foreach(UNIT_TEST IN LISTS UNIT_TESTS)
    add_executable(${UNIT_TEST} ${UNIT_TEST}.cpp)
    target_link_libraries(${UNIT_TEST} ${UNIT_TEST_LIBS})
endforeach (UNIT_TEST)


