cmake_minimum_required(VERSION 3.6)
project(01Observer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Observer/IObserver.cpp Observer/IObserver.h Observer/ProductObserver.cpp Observer/ProductObserver.h Subject/ISubject.cpp Subject/ISubject.h Subject/ActionSubject.cpp Subject/ActionSubject.h)
add_executable(01Observer ${SOURCE_FILES})