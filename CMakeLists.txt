cmake_minimum_required(VERSION 3.12)

# set the project name
project(Elevation)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-O3 -Wall -Wextra -Werror)

add_subdirectory(src)

#
# TESTS create and configure the unit test target
#

option(Elevation_BuildTests
       "Build the unit tests when BUILD_TESTING is enabled." ON)

include(CTest) # adds option BUILD_TESTING (default ON)

if(BUILD_TESTING AND Elevation_BuildTests)
  enable_testing()
  add_subdirectory(test)
endif()
