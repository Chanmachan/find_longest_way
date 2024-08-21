cmake_minimum_required(VERSION 3.26)
project(find_longest_way)

set(CMAKE_CXX_STANDARD 14)

add_executable(find_longest_way
               src/main.cpp
               src/longest_way.cpp)

add_library(test_library src/longest_way.cpp)

add_subdirectory(test)