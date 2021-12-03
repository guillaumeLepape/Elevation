project(concrete_entity)

add_library(
    ${PROJECT_NAME} 
    src/Id.cpp
    src/Player.cpp 
    src/Plug.cpp 
    src/ResultsData.cpp
)

target_include_directories(
    ${PROJECT_NAME} 
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC entity
)