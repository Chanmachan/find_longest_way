cmake_minimum_required(VERSION 3.26)
project(find_longest_way)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
add_test(NAME TestName COMMAND exe_test)