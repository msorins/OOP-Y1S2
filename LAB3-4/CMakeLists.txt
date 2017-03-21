cmake_minimum_required(VERSION 3.6)
project(LAB3_4)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c MedUI.c MedUI.h MedController.c MedController.h MedDomain.c MedDomain.h MedRepository.c MedRepository.h DynamicArray.h DynamicArray.c tests.h tests.c Operation.c Operation.h)
add_executable(LAB3_4 ${SOURCE_FILES})