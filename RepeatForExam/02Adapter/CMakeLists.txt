cmake_minimum_required(VERSION 3.6)
project(02Adapter)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Old/OldRectangle.cpp Old/OldRectangle.h New/INewRectangle.cpp New/INewRectangle.h Adapter/RectangleAdapter.cpp Adapter/RectangleAdapter.h)
add_executable(02Adapter ${SOURCE_FILES})