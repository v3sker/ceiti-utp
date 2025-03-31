cmake_minimum_required(VERSION 3.30)
project(UTCP2)

set(CMAKE_CXX_STANDARD 20)

add_executable(UTCP2 main.cpp
        sort.cpp
        find.cpp
        find.h)
