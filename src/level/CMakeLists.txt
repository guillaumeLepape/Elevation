project(level)

add_library(
    ${PROJECT_NAME}
    src/Introduction.cpp
    src/Level1.cpp
    src/Level2.cpp
    src/Level3.cpp
    src/Level4.cpp
    src/Level5.cpp
    src/Level6.cpp
    src/Level7.cpp
    src/Level8.cpp
    src/Level9.cpp
    src/Level10.cpp
    src/Outro.cpp
    src/LevelUtils.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC fight
)