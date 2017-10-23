cmake_minimum_required(VERSION 3.7)
project(quiz_hybrid_a)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp hybrid_breadth_first.cpp hybrid_breadth_first.h)
add_executable(quiz_hybrid_a ${SOURCE_FILES})