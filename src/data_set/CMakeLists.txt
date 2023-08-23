find_package(fmt CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(range-v3 CONFIG REQUIRED)

add_executable(dataset
    main.cpp
)

target_link_libraries(
    dataset
    PRIVATE fmt::fmt
    PRIVATE nlohmann_json::nlohmann_json
    PRIVATE range-v3::meta range-v3::concepts range-v3::range-v3
)
