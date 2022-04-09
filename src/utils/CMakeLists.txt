project(utils)

add_library(
    ${PROJECT_NAME}
    src/options.cpp
    src/pause.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC fmt
    PUBLIC range-v3
    PUBLIC stduuid
)