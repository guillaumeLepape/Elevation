project(action)

add_library(
    ${PROJECT_NAME}
    src/ActionWriter.cpp
    src/Dead.cpp
    src/AddWeaponAction.cpp
    src/Negociate.cpp
    src/Pseudo.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    ${PROJECT_NAME} 
    PUBLIC writer
    PUBLIC entity
)