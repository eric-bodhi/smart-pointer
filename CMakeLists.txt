cmake_minimum_required(VERSION 3.26)
project(smart_pointer)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(smart_pointer
        main.cpp
        unique_ptr.hpp)