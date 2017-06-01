cmake_minimum_required(VERSION 3.7)
project(03Composite)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp IGraphic.cpp IGraphic.h Line.cpp Line.h Rectangle.cpp Rectangle.h Picture.cpp Picture.h)
add_executable(03Composite ${SOURCE_FILES})