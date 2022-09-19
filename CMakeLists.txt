cmake_minimum_required(VERSION 3.16)

set(SOURCES
    catch.hpp
    list_tests.cc
    List.cpp
    test_main.cc
    List.h
)

project(lab2)
add_executable(lab2 ${SOURCES})

target_compile_options(lab2 PRIVATE -Wall -Wextra -pedantic -Weffc++ -Wold-style-cast)




