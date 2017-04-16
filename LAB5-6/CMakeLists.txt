cmake_minimum_required(VERSION 3.6)
project(LAB5_6)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp List/DynamicArray.cpp List/DynamicArray.h Model/Movie.cpp Model/Movie.h Repository/MovieRepository.cpp Repository/MovieRepository.h Controller/MovieController.cpp Controller/MovieController.h UI/UI.cpp UI/UI.h Tests/Tests.cpp Tests/Tests.h Model/WatchListItem.cpp Model/WatchListItem.h Repository/IWatchListRepository.cpp Repository/IWatchListRepository.h List/IDynamicArray.cpp List/IDynamicArray.h List/STLVector.cpp List/STLVector.h Others/Iterator.cpp Others/Iterator.h Others/Exception.cpp Others/Exception.h Repository/IMovieRepository.cpp Repository/IMovieRepository.h Repository/MemoryMovieRepository.cpp Repository/MemoryMovieRepository.h Repository/FileMovieRepository.cpp Repository/FileMovieRepository.h Repository/CSVWatchListRepository.cpp Repository/CSVWatchListRepository.h Repository/HTMLWatchListRepository.cpp Repository/HTMLWatchListRepository.h)
add_executable(LAB5_6 ${SOURCE_FILES})