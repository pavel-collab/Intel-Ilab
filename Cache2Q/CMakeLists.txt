cmake_minimum_required (VERSION 3.11)
project (2QCache LANGUAGES CXX)

include_directories("include/")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O3")

set(SRC_MAIN src/main.cpp)
set(SRC_TESTS tests/tests.cpp)

add_executable (out ${SRC_MAIN})
add_executable (test ${SRC_TESTS})
