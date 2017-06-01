cmake_minimum_required(VERSION 3.6)
project(WLM)

set(CMAKE_CXX_STANDARD 11)
set( CMAKE_AUTOMOC ON )  # to automoc remove the

set(SOURCE_FILES main.cpp UI/listmodel.cpp UI/listmodel.h UI/mainwindow.cpp UI/mainwindow.h UI/ui_mainwindow.h MODEL/Bill.cpp MODEL/Bill.h Repository/Repository.cpp Repository/Repository.h CONTROLLER/Controller.cpp CONTROLLER/Controller.h)
add_executable(WLM ${SOURCE_FILES})


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



target_link_libraries(WLM Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Charts)

# Qt5 -- END SECTION --