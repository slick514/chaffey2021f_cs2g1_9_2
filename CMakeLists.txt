cmake_minimum_required(VERSION 3.20)
project(chaffey2021f_cs2g1_9_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(chaffey2021f_cs2g1_9_2 main.cpp)
add_executable(chaffey2021f_cs2g1_9_2_person main.cpp person.cpp)
add_library(test_library STATIC person.cpp)