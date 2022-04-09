project(level)

add_library(
    ${PROJECT_NAME}
    src/introduction.cpp
    src/level1.cpp
    src/level2.cpp
    src/level3.cpp
    src/level4.cpp
    src/level5.cpp
    src/level6.cpp
    src/level7.cpp
    src/level8.cpp
    src/level9.cpp
    src/level10.cpp
    src/outro.cpp
    src/level_utils.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC fight
)