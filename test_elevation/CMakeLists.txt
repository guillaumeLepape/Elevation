project(test_elevation)

add_executable(
    ${PROJECT_NAME}
    test.cpp
    weaponTest.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE concrete_entity
    PRIVATE data_files
    PRIVATE action
    PRIVATE entity
    PRIVATE gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_elevation)