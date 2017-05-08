cmake_minimum_required(VERSION 3.6)
project(Test2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Person.cpp Person.h MedicalAnalysis.cpp MedicalAnalysis.h BMI.cpp BMI.h BP.cpp BP.h Date.cpp Date.h Exception.cpp Exception.h UI.cpp UI.h)
add_executable(Test2 ${SOURCE_FILES})