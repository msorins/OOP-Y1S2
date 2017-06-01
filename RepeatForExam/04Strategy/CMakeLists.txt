cmake_minimum_required(VERSION 3.7)
project(04Strategy)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ISave.cpp ISave.h SaveConsole.cpp SaveConsole.h SaveFile.cpp SaveFile.h)
add_executable(04Strategy ${SOURCE_FILES})