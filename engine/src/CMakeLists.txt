add_library(tetris_core
    Grid.cpp
    GridState.cpp
    Shape.cpp
    ShapeState.cpp
    Utils.cpp
)

target_include_directories(tetris_core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_compile_options(tetris_core PRIVATE
    -Wall -Wextra -Wpedantic
)
