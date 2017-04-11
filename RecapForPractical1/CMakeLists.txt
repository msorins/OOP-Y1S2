cmake_minimum_required(VERSION 3.6)
project(RecapForPractical1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DynamicArray.cpp DynamicArray.h)
add_executable(RecapForPractical1 ${SOURCE_FILES})