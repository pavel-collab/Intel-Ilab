cmake_minimum_required (VERSION 3.11)
project (2QCache LANGUAGES CXX)

set(SRC_MAIN src/main.cpp)

include_directories("include/")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -O3")

add_executable (out ${SRC_MAIN})