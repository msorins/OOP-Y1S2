cmake_minimum_required(VERSION 3.6)
project(LAB5_6)

set(CMAKE_CXX_STANDARD 14)
set( CMAKE_AUTOMOC ON )  # to automoc remove the

set(SOURCE_FILES main.cpp List/DynamicArray.cpp List/DynamicArray.h Model/Movie.cpp Model/Movie.h Repository/MovieRepository.cpp Repository/MovieRepository.h Controller/MovieController.cpp Controller/MovieController.h UI/UI.cpp UI/UI.h Tests/Tests.cpp Tests/Tests.h Model/WatchListItem.cpp Model/WatchListItem.h Repository/IWatchListRepository.cpp Repository/IWatchListRepository.h List/IDynamicArray.cpp List/IDynamicArray.h List/STLVector.cpp List/STLVector.h Others/Iterator.cpp Others/Iterator.h Others/Exception.cpp Others/Exception.h Repository/IMovieRepository.cpp Repository/IMovieRepository.h Repository/MemoryMovieRepository.cpp Repository/MemoryMovieRepository.h Repository/FileMovieRepository.cpp Repository/FileMovieRepository.h Repository/CSVWatchListRepository.cpp Repository/CSVWatchListRepository.h Repository/HTMLWatchListRepository.cpp Repository/HTMLWatchListRepository.h Repository/MemoryWatchListRepository.cpp Repository/MemoryWatchListRepository.h UI/MainWindow.cpp UI/MainWindow.h UI/Ui_MainWindow.cpp UI/Ui_MainWindow.h)
add_executable(LAB5_6 ${SOURCE_FILES})



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



target_link_libraries(LAB5_6 Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Charts)

# Qt5 -- END SECTION --



