cmake_minimum_required(VERSION 3.7)
project(Simulation)

set(CMAKE_CXX_STANDARD 11)
set( CMAKE_AUTOMOC ON )  # to automoc remove the

set(SOURCE_FILES main.cpp UI/mainwindow.h UI/UI_ListModel.cpp UI/UI_ListModel.h UI/ui_mainwindow.h UI/mainwindow.cpp Model/Weather.cpp Model/Weather.h Repository/Repository.cpp Repository/Repository.h UI/CustomProxyModel.cpp UI/CustomProxyModel.h UI/UI_TableModel.cpp UI/UI_TableModel.h)
add_executable(Simulation ${SOURCE_FILES})


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



target_link_libraries(Simulation Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Charts)

# Qt5 -- END SECTION --

