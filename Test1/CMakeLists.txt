cmake_minimum_required(VERSION 3.6)
project(Test10APR)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ProjectModel.cpp ProjectModel.h ProjectRepository.cpp ProjectRepository.h UI.cpp UI.h ProjectController.cpp ProjectController.h Tests.cpp Tests.h)
add_executable(Test10APR ${SOURCE_FILES})