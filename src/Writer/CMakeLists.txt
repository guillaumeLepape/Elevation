project(writer)

add_library(
    ${PROJECT_NAME}
    src/Rules.cpp
    src/HeaderWriter.cpp
    src/MessageWriter.cpp
    src/SelectionWriter.cpp
    src/TutorialWriter.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC utils
    PUBLIC data_files
    PUBLIC cpp-terminal
)