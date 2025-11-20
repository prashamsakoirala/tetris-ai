enable_testing()

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)
FetchContent_MakeAvailable(googletest)

add_executable(tetris_tests
    test_shapes.cpp
)

target_include_directories(tetris_tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(tetris_tests PRIVATE
    tetris_core
    GTest::gtest
    GTest::gtest_main
)

target_compile_options(tetris_tests PRIVATE
    -Wall -Wextra -Wpedantic
)

include(GoogleTest)
gtest_discover_tests(tetris_tests)
