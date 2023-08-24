project(utils)

find_package(fmt CONFIG REQUIRED)
find_package(stduuid CONFIG REQUIRED)
find_package(range-v3 CONFIG REQUIRED)

add_library(${PROJECT_NAME} src/options.cpp src/pause.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(
  ${PROJECT_NAME} PUBLIC fmt::fmt range-v3::meta range-v3::concepts
                         range-v3::range-v3 stduuid)
