project(data_files)

find_package(fmt CONFIG REQUIRED)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME}
                           INTERFACE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} INTERFACE fmt::fmt)
