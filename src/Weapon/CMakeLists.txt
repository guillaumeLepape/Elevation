project(weapon)

add_library(
    ${PROJECT_NAME}
    src/WeaponInventory.cpp
    src/WeaponWriter.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC utils
    PUBLIC entity
    PUBLIC data_files
    PUBLIC data
    PUBLIC cpp-terminal
)