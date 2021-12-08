project(selection)

add_library(
    ${PROJECT_NAME} 
    src/Question.cpp
    src/Selection.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC writer
)