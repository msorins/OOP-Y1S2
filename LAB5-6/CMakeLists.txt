cmake_minimum_required(VERSION 3.6)
project(LAB5_6)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DynamicArray.cpp DynamicArray.h Movie.cpp Movie.h MovieRepository.cpp MovieRepository.h MovieController.cpp MovieController.h UI.cpp UI.h Tests.cpp Tests.h WatchListItem.cpp WatchListItem.h WatchListRepository.cpp WatchListRepository.h IDynamicArray.cpp IDynamicArray.h STLVector.cpp STLVector.h Iterator.cpp Iterator.h)
add_executable(LAB5_6 ${SOURCE_FILES})