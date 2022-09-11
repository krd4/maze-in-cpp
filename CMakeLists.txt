cmake_minimum_required(VERSION 3.14)

project(maze)

# Google test require at least c++14
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)
add_subdirectory(test)