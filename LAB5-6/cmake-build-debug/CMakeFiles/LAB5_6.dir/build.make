# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/so/Desktop/UBB/OOP/LAB5-6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/so/Desktop/UBB/OOP/LAB5-6/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LAB5_6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LAB5_6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LAB5_6.dir/flags.make

CMakeFiles/LAB5_6.dir/main.cpp.o: CMakeFiles/LAB5_6.dir/flags.make
CMakeFiles/LAB5_6.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/so/Desktop/UBB/OOP/LAB5-6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LAB5_6.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LAB5_6.dir/main.cpp.o -c /Users/so/Desktop/UBB/OOP/LAB5-6/main.cpp

CMakeFiles/LAB5_6.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LAB5_6.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/so/Desktop/UBB/OOP/LAB5-6/main.cpp > CMakeFiles/LAB5_6.dir/main.cpp.i

CMakeFiles/LAB5_6.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LAB5_6.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/so/Desktop/UBB/OOP/LAB5-6/main.cpp -o CMakeFiles/LAB5_6.dir/main.cpp.s

CMakeFiles/LAB5_6.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/LAB5_6.dir/main.cpp.o.requires

CMakeFiles/LAB5_6.dir/main.cpp.o.provides: CMakeFiles/LAB5_6.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/LAB5_6.dir/build.make CMakeFiles/LAB5_6.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/LAB5_6.dir/main.cpp.o.provides

CMakeFiles/LAB5_6.dir/main.cpp.o.provides.build: CMakeFiles/LAB5_6.dir/main.cpp.o


CMakeFiles/LAB5_6.dir/DynamicArray.cpp.o: CMakeFiles/LAB5_6.dir/flags.make
CMakeFiles/LAB5_6.dir/DynamicArray.cpp.o: ../DynamicArray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/so/Desktop/UBB/OOP/LAB5-6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LAB5_6.dir/DynamicArray.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LAB5_6.dir/DynamicArray.cpp.o -c /Users/so/Desktop/UBB/OOP/LAB5-6/DynamicArray.cpp

CMakeFiles/LAB5_6.dir/DynamicArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LAB5_6.dir/DynamicArray.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/so/Desktop/UBB/OOP/LAB5-6/DynamicArray.cpp > CMakeFiles/LAB5_6.dir/DynamicArray.cpp.i

CMakeFiles/LAB5_6.dir/DynamicArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LAB5_6.dir/DynamicArray.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/so/Desktop/UBB/OOP/LAB5-6/DynamicArray.cpp -o CMakeFiles/LAB5_6.dir/DynamicArray.cpp.s

CMakeFiles/LAB5_6.dir/DynamicArray.cpp.o.requires:

.PHONY : CMakeFiles/LAB5_6.dir/DynamicArray.cpp.o.requires

CMakeFiles/LAB5_6.dir/DynamicArray.cpp.o.provides: CMakeFiles/LAB5_6.dir/DynamicArray.cpp.o.requires
	$(MAKE) -f CMakeFiles/LAB5_6.dir/build.make CMakeFiles/LAB5_6.dir/DynamicArray.cpp.o.provides.build
.PHONY : CMakeFiles/LAB5_6.dir/DynamicArray.cpp.o.provides

CMakeFiles/LAB5_6.dir/DynamicArray.cpp.o.provides.build: CMakeFiles/LAB5_6.dir/DynamicArray.cpp.o


CMakeFiles/LAB5_6.dir/Movie.cpp.o: CMakeFiles/LAB5_6.dir/flags.make
CMakeFiles/LAB5_6.dir/Movie.cpp.o: ../Movie.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/so/Desktop/UBB/OOP/LAB5-6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/LAB5_6.dir/Movie.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LAB5_6.dir/Movie.cpp.o -c /Users/so/Desktop/UBB/OOP/LAB5-6/Movie.cpp

CMakeFiles/LAB5_6.dir/Movie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LAB5_6.dir/Movie.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/so/Desktop/UBB/OOP/LAB5-6/Movie.cpp > CMakeFiles/LAB5_6.dir/Movie.cpp.i

CMakeFiles/LAB5_6.dir/Movie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LAB5_6.dir/Movie.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/so/Desktop/UBB/OOP/LAB5-6/Movie.cpp -o CMakeFiles/LAB5_6.dir/Movie.cpp.s

CMakeFiles/LAB5_6.dir/Movie.cpp.o.requires:

.PHONY : CMakeFiles/LAB5_6.dir/Movie.cpp.o.requires

CMakeFiles/LAB5_6.dir/Movie.cpp.o.provides: CMakeFiles/LAB5_6.dir/Movie.cpp.o.requires
	$(MAKE) -f CMakeFiles/LAB5_6.dir/build.make CMakeFiles/LAB5_6.dir/Movie.cpp.o.provides.build
.PHONY : CMakeFiles/LAB5_6.dir/Movie.cpp.o.provides

CMakeFiles/LAB5_6.dir/Movie.cpp.o.provides.build: CMakeFiles/LAB5_6.dir/Movie.cpp.o


CMakeFiles/LAB5_6.dir/MovieRepository.cpp.o: CMakeFiles/LAB5_6.dir/flags.make
CMakeFiles/LAB5_6.dir/MovieRepository.cpp.o: ../MovieRepository.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/so/Desktop/UBB/OOP/LAB5-6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/LAB5_6.dir/MovieRepository.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LAB5_6.dir/MovieRepository.cpp.o -c /Users/so/Desktop/UBB/OOP/LAB5-6/MovieRepository.cpp

CMakeFiles/LAB5_6.dir/MovieRepository.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LAB5_6.dir/MovieRepository.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/so/Desktop/UBB/OOP/LAB5-6/MovieRepository.cpp > CMakeFiles/LAB5_6.dir/MovieRepository.cpp.i

CMakeFiles/LAB5_6.dir/MovieRepository.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LAB5_6.dir/MovieRepository.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/so/Desktop/UBB/OOP/LAB5-6/MovieRepository.cpp -o CMakeFiles/LAB5_6.dir/MovieRepository.cpp.s

CMakeFiles/LAB5_6.dir/MovieRepository.cpp.o.requires:

.PHONY : CMakeFiles/LAB5_6.dir/MovieRepository.cpp.o.requires

CMakeFiles/LAB5_6.dir/MovieRepository.cpp.o.provides: CMakeFiles/LAB5_6.dir/MovieRepository.cpp.o.requires
	$(MAKE) -f CMakeFiles/LAB5_6.dir/build.make CMakeFiles/LAB5_6.dir/MovieRepository.cpp.o.provides.build
.PHONY : CMakeFiles/LAB5_6.dir/MovieRepository.cpp.o.provides

CMakeFiles/LAB5_6.dir/MovieRepository.cpp.o.provides.build: CMakeFiles/LAB5_6.dir/MovieRepository.cpp.o


CMakeFiles/LAB5_6.dir/MovieController.cpp.o: CMakeFiles/LAB5_6.dir/flags.make
CMakeFiles/LAB5_6.dir/MovieController.cpp.o: ../MovieController.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/so/Desktop/UBB/OOP/LAB5-6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/LAB5_6.dir/MovieController.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LAB5_6.dir/MovieController.cpp.o -c /Users/so/Desktop/UBB/OOP/LAB5-6/MovieController.cpp

CMakeFiles/LAB5_6.dir/MovieController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LAB5_6.dir/MovieController.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/so/Desktop/UBB/OOP/LAB5-6/MovieController.cpp > CMakeFiles/LAB5_6.dir/MovieController.cpp.i

CMakeFiles/LAB5_6.dir/MovieController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LAB5_6.dir/MovieController.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/so/Desktop/UBB/OOP/LAB5-6/MovieController.cpp -o CMakeFiles/LAB5_6.dir/MovieController.cpp.s

CMakeFiles/LAB5_6.dir/MovieController.cpp.o.requires:

.PHONY : CMakeFiles/LAB5_6.dir/MovieController.cpp.o.requires

CMakeFiles/LAB5_6.dir/MovieController.cpp.o.provides: CMakeFiles/LAB5_6.dir/MovieController.cpp.o.requires
	$(MAKE) -f CMakeFiles/LAB5_6.dir/build.make CMakeFiles/LAB5_6.dir/MovieController.cpp.o.provides.build
.PHONY : CMakeFiles/LAB5_6.dir/MovieController.cpp.o.provides

CMakeFiles/LAB5_6.dir/MovieController.cpp.o.provides.build: CMakeFiles/LAB5_6.dir/MovieController.cpp.o


CMakeFiles/LAB5_6.dir/UI.cpp.o: CMakeFiles/LAB5_6.dir/flags.make
CMakeFiles/LAB5_6.dir/UI.cpp.o: ../UI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/so/Desktop/UBB/OOP/LAB5-6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/LAB5_6.dir/UI.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LAB5_6.dir/UI.cpp.o -c /Users/so/Desktop/UBB/OOP/LAB5-6/UI.cpp

CMakeFiles/LAB5_6.dir/UI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LAB5_6.dir/UI.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/so/Desktop/UBB/OOP/LAB5-6/UI.cpp > CMakeFiles/LAB5_6.dir/UI.cpp.i

CMakeFiles/LAB5_6.dir/UI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LAB5_6.dir/UI.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/so/Desktop/UBB/OOP/LAB5-6/UI.cpp -o CMakeFiles/LAB5_6.dir/UI.cpp.s

CMakeFiles/LAB5_6.dir/UI.cpp.o.requires:

.PHONY : CMakeFiles/LAB5_6.dir/UI.cpp.o.requires

CMakeFiles/LAB5_6.dir/UI.cpp.o.provides: CMakeFiles/LAB5_6.dir/UI.cpp.o.requires
	$(MAKE) -f CMakeFiles/LAB5_6.dir/build.make CMakeFiles/LAB5_6.dir/UI.cpp.o.provides.build
.PHONY : CMakeFiles/LAB5_6.dir/UI.cpp.o.provides

CMakeFiles/LAB5_6.dir/UI.cpp.o.provides.build: CMakeFiles/LAB5_6.dir/UI.cpp.o


CMakeFiles/LAB5_6.dir/Tests.cpp.o: CMakeFiles/LAB5_6.dir/flags.make
CMakeFiles/LAB5_6.dir/Tests.cpp.o: ../Tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/so/Desktop/UBB/OOP/LAB5-6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/LAB5_6.dir/Tests.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LAB5_6.dir/Tests.cpp.o -c /Users/so/Desktop/UBB/OOP/LAB5-6/Tests.cpp

CMakeFiles/LAB5_6.dir/Tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LAB5_6.dir/Tests.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/so/Desktop/UBB/OOP/LAB5-6/Tests.cpp > CMakeFiles/LAB5_6.dir/Tests.cpp.i

CMakeFiles/LAB5_6.dir/Tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LAB5_6.dir/Tests.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/so/Desktop/UBB/OOP/LAB5-6/Tests.cpp -o CMakeFiles/LAB5_6.dir/Tests.cpp.s

CMakeFiles/LAB5_6.dir/Tests.cpp.o.requires:

.PHONY : CMakeFiles/LAB5_6.dir/Tests.cpp.o.requires

CMakeFiles/LAB5_6.dir/Tests.cpp.o.provides: CMakeFiles/LAB5_6.dir/Tests.cpp.o.requires
	$(MAKE) -f CMakeFiles/LAB5_6.dir/build.make CMakeFiles/LAB5_6.dir/Tests.cpp.o.provides.build
.PHONY : CMakeFiles/LAB5_6.dir/Tests.cpp.o.provides

CMakeFiles/LAB5_6.dir/Tests.cpp.o.provides.build: CMakeFiles/LAB5_6.dir/Tests.cpp.o


# Object files for target LAB5_6
LAB5_6_OBJECTS = \
"CMakeFiles/LAB5_6.dir/main.cpp.o" \
"CMakeFiles/LAB5_6.dir/DynamicArray.cpp.o" \
"CMakeFiles/LAB5_6.dir/Movie.cpp.o" \
"CMakeFiles/LAB5_6.dir/MovieRepository.cpp.o" \
"CMakeFiles/LAB5_6.dir/MovieController.cpp.o" \
"CMakeFiles/LAB5_6.dir/UI.cpp.o" \
"CMakeFiles/LAB5_6.dir/Tests.cpp.o"

# External object files for target LAB5_6
LAB5_6_EXTERNAL_OBJECTS =

LAB5_6: CMakeFiles/LAB5_6.dir/main.cpp.o
LAB5_6: CMakeFiles/LAB5_6.dir/DynamicArray.cpp.o
LAB5_6: CMakeFiles/LAB5_6.dir/Movie.cpp.o
LAB5_6: CMakeFiles/LAB5_6.dir/MovieRepository.cpp.o
LAB5_6: CMakeFiles/LAB5_6.dir/MovieController.cpp.o
LAB5_6: CMakeFiles/LAB5_6.dir/UI.cpp.o
LAB5_6: CMakeFiles/LAB5_6.dir/Tests.cpp.o
LAB5_6: CMakeFiles/LAB5_6.dir/build.make
LAB5_6: CMakeFiles/LAB5_6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/so/Desktop/UBB/OOP/LAB5-6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable LAB5_6"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LAB5_6.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LAB5_6.dir/build: LAB5_6

.PHONY : CMakeFiles/LAB5_6.dir/build

CMakeFiles/LAB5_6.dir/requires: CMakeFiles/LAB5_6.dir/main.cpp.o.requires
CMakeFiles/LAB5_6.dir/requires: CMakeFiles/LAB5_6.dir/DynamicArray.cpp.o.requires
CMakeFiles/LAB5_6.dir/requires: CMakeFiles/LAB5_6.dir/Movie.cpp.o.requires
CMakeFiles/LAB5_6.dir/requires: CMakeFiles/LAB5_6.dir/MovieRepository.cpp.o.requires
CMakeFiles/LAB5_6.dir/requires: CMakeFiles/LAB5_6.dir/MovieController.cpp.o.requires
CMakeFiles/LAB5_6.dir/requires: CMakeFiles/LAB5_6.dir/UI.cpp.o.requires
CMakeFiles/LAB5_6.dir/requires: CMakeFiles/LAB5_6.dir/Tests.cpp.o.requires

.PHONY : CMakeFiles/LAB5_6.dir/requires

CMakeFiles/LAB5_6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LAB5_6.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LAB5_6.dir/clean

CMakeFiles/LAB5_6.dir/depend:
	cd /Users/so/Desktop/UBB/OOP/LAB5-6/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/so/Desktop/UBB/OOP/LAB5-6 /Users/so/Desktop/UBB/OOP/LAB5-6 /Users/so/Desktop/UBB/OOP/LAB5-6/cmake-build-debug /Users/so/Desktop/UBB/OOP/LAB5-6/cmake-build-debug /Users/so/Desktop/UBB/OOP/LAB5-6/cmake-build-debug/CMakeFiles/LAB5_6.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LAB5_6.dir/depend

