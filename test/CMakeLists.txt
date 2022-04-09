project(test1)

add_executable(
    ${PROJECT_NAME}
    test.cpp
    weapon_test.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE weapon
    PRIVATE data_files
    PRIVATE action
    PRIVATE entity
    PRIVATE gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})