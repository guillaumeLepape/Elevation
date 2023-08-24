project(data)

find_package(nlohmann_json CONFIG REQUIRED)
find_package(range-v3 CONFIG REQUIRED)

add_library(${PROJECT_NAME} src/list_name_data.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(
  ${PROJECT_NAME} PUBLIC utils nlohmann_json::nlohmann_json range-v3::meta
                         range-v3::concepts range-v3::range-v3)
