cmake_minimum_required (VERSION 3.11)
project ("2QCache" LANGUAGES CXX)

# THE 17TH STANDART
set(CMAKE_CXX_STANDARD 17)

# EXECUTABLE FILE PROPERTIES
set(MAIN          "main")
set(PERFECT_CACHE "perfect")

# SRC FILES
set(SRC_MAIN src/main.cpp)
set(SRC_PERFECT_CACHE src/perfect_cache.cpp)

# EXECUTABLES
add_executable(${MAIN} ${SRC_MAIN})
add_executable(${PERFECT_CACHE} ${SRC_PERFECT_CACHE})

# TARGETS INCLUDE DERICTORIES
target_include_directories(${MAIN}            PRIVATE include src)
target_include_directories(${PERFECT_CACHE}   PRIVATE include src)

add_compile_options(
    -O2    

    -Werror

    -Wall
    -Wextra
    -Wpedantic

    -Wnarrowing 
    -Wwrite-strings 
    -Wcast-qual 
    -Wundef 
    -Wstrict-prototypes 
    -Wbad-function-cast
)