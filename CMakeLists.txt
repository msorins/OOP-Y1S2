cmake_minimum_required(VERSION 3.6)
project(OOP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        LAB1/cmake-build-debug/cmake_install.cmake
        LAB1/cmake-build-debug/CMakeCache.txt
        LAB1/cmake-build-debug/Lab1
        LAB1/cmake-build-debug/Lab1.cbp
        LAB1/cmake-build-debug/Makefile
        LAB1/CMakeLists.txt
        LAB1/main.c
        LAB3-4/cmake-build-debug/cmake_install.cmake
        LAB3-4/cmake-build-debug/CMakeCache.txt
        LAB3-4/cmake-build-debug/LAB3_4
        LAB3-4/cmake-build-debug/LAB3_4.cbp
        LAB3-4/cmake-build-debug/Makefile
        LAB3-4/CMakeLists.txt
        LAB3-4/main.c
        LAB3-4/MedController.c
        LAB3-4/MedController.h
        LAB3-4/MedDomain.c
        LAB3-4/MedDomain.h
        LAB3-4/MedRepository.c
        LAB3-4/MedRepository.h
        LAB3-4/MedUI.c
        LAB3-4/MedUI.h
        Seminar1/cmake-build-debug/cmake_install.cmake
        Seminar1/cmake-build-debug/CMakeCache.txt
        Seminar1/cmake-build-debug/Makefile
        Seminar1/cmake-build-debug/Seminar1.cbp
        Seminar1/bla.cpp
        Seminar1/CMakeLists.txt
        Seminar1/library.c
        Seminar1/library.h)

add_executable(OOP ${SOURCE_FILES})