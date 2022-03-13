project(fight)

add_library(
    ${PROJECT_NAME}
    src/FightWriter.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC action
    PUBLIC selection
    PUBLIC tabulate::tabulate
)