cmake_minimum_required(VERSION 3.6)
project(WTM)

set(CMAKE_CXX_STANDARD 11)
set( CMAKE_AUTOMOC ON )  # to automoc remove the

set(SOURCE_FILES main.cpp UI/mainwindow.cpp UI/mainwindow.h UI/tablemodel.cpp UI/tablemodel.h UI/ui_mainwindow.h UI/ui_mainwindow.cpp Model/Student.cpp Model/Student.h Repository/StudentsRepository.cpp Repository/StudentsRepository.h Controller/GradingController.cpp Controller/GradingController.h UI/customProxyTableModel.cpp UI/customProxyTableModel.h Repository/TeachersRepository.cpp Repository/TeachersRepository.h Model/Teacher.cpp Model/Teacher.h Exception/Exception.cpp Exception/Exception.h)
add_executable(WTM ${SOURCE_FILES})

# Qt5 -- BEGIN SECTION --
set(QT_DIR /Users/so/Qt5.8.0/5.8/clang_64/lib/cmake/Qt5Core/)
set(Qt5Widgets_DIR /Users/so/Qt5.8.0/5.8/clang_64/lib/cmake/Qt5Widgets/)
set(Qt5OpenGL_DIR /Users/so/Qt5.8.0/5.8/clang_64/lib/cmake/Qt5OpenGL/)
set(Qt5Multimedia_DIR /Users/so/Qt5.8.0/5.8/clang_64/lib/cmake/Qt5Multimedia/)
set(Qt5Charts_DIR /Users/so/Qt5.8.0/5.8/clang_64/lib/cmake/Qt5Charts/)

set (CMAKE_INSTALL_PREFIX /Users/so/Qt5.8.0/5.8/clang_64/lib/cmake/Qt5Core)
set(CMAKE_PREFIX_PATH  /Users/so/Qt5.8.0/5.8/clang_64/lib/cmake/Qt5Core)

find_package( Qt5Core REQUIRED )
find_package( Qt5Widgets REQUIRED )
find_package( Qt5Gui REQUIRED )
find_package( Qt5OpenGL REQUIRED )
find_package( Qt5Multimedia REQUIRED )
find_package( Qt5Charts REQUIRED )



target_link_libraries(WTM Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Charts)