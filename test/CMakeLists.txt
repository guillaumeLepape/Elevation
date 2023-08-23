project(test_elevation)

find_package(GTest CONFIG REQUIRED)

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
    PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main
)

add_test(AllTestsInMain main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
