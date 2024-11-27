cmake_minimum_required(VERSION 3.28)
project(Lab5)

set(CMAKE_CXX_STANDARD 23)

add_executable(Lab5 main.cpp
        print.h
        print.cpp
        matrix.h
        matrix.cpp
        handle_errors.h
        handle_errors.cpp
)
