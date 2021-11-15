cmake_minimum_required (VERSION 3.11)
project (2QCache LANGUAGES CXX)

set(SRC_MAIN src/main.cpp)

include_directories("include/")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -O3")

set(SRC_MAIN src/main.cpp)
set(SRC_PERFECT src/perfect_cache.cpp)

add_executable (main ${SRC_MAIN})
add_executable (perfect ${SRC_MAIN})
