cmake_minimum_required (VERSION 3.11)
project (2QCache LANGUAGES CXX)

set(SRC_PATH "src/main.cpp")
set(TESTS_PATH "tests/tests.cpp")

add_executable(out ${SRC_PATH})
add_executable(tests ${TESTS_PATH})