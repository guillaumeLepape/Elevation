project(writer)

add_library(${PROJECT_NAME} src/rules.cpp src/message_writer.cpp
                            src/utils_writer.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PUBLIC utils data_files)
