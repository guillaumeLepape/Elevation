cmake_minimum_required(VERSION 3.12)

# set the project name
project(Elevation VERSION 1.0.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-O3 -Wall -Wextra -Werror -fconcepts)

add_subdirectory(src)

# add tabulate library
add_subdirectory(libraries/tabulate)

# add json library
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(libraries/json) 

# add cpp-terminal library
add_subdirectory(libraries/cpp-terminal)

##
## TESTS
## create and configure the unit test target
##

option(Elevation_BuildTests "Build the unit tests when BUILD_TESTING is enabled." ON)

include(CTest) #adds option BUILD_TESTING (default ON)

if(BUILD_TESTING AND Elevation_BuildTests)
    #add google test library
    add_subdirectory(libraries/googletest)
    enable_testing()
    add_subdirectory(test)
endif()
