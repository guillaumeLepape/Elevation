project(entity)

find_package(nlohmann_json_schema_validator REQUIRED)

add_library(${PROJECT_NAME} src/player.cpp src/plug.cpp src/results.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE nlohmann_json_schema_validator
  PUBLIC weapon)
