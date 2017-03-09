cmake_minimum_required(VERSION 3.6)
project(Seminar1)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES library.c library.h bla.cpp)
add_library(Seminar1 ${SOURCE_FILES})