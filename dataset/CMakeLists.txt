add_executable(dataset
    dataset/main.cpp
)

target_link_libraries(
    dataset 
    PRIVATE nlohmann_json::nlohmann_json 
)