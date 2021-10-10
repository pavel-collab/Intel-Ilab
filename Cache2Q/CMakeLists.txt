cmake_minimum_required (VERSION 3.11)
project (2QCache LANGUAGES CXX)

message(STATUS "OS: ${CMAKE_SYSTEM_NAME}")

add_executable (out main.cpp)