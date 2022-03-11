project(data)

add_library(
    ${PROJECT_NAME}
    src/Data.cpp
    src/ListNameData.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC nlohmann_json::nlohmann_json 
    PUBLIC fmt
    PUBLIC range-v3
)