project(data)

add_library(
    ${PROJECT_NAME}
    src/ListNameData.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC utils
    PUBLIC nlohmann_json::nlohmann_json 
    PUBLIC range-v3
)