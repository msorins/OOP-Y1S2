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
CMAKE_SOURCE_DIR = /Users/so/Desktop/UBB/OOP2/TestPolymorphism

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/so/Desktop/UBB/OOP2/TestPolymorphism/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TestPolymorphism.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TestPolymorphism.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestPolymorphism.dir/flags.make

CMakeFiles/TestPolymorphism.dir/main.cpp.o: CMakeFiles/TestPolymorphism.dir/flags.make
CMakeFiles/TestPolymorphism.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/so/Desktop/UBB/OOP2/TestPolymorphism/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestPolymorphism.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestPolymorphism.dir/main.cpp.o -c /Users/so/Desktop/UBB/OOP2/TestPolymorphism/main.cpp

CMakeFiles/TestPolymorphism.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestPolymorphism.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/so/Desktop/UBB/OOP2/TestPolymorphism/main.cpp > CMakeFiles/TestPolymorphism.dir/main.cpp.i

CMakeFiles/TestPolymorphism.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestPolymorphism.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/so/Desktop/UBB/OOP2/TestPolymorphism/main.cpp -o CMakeFiles/TestPolymorphism.dir/main.cpp.s

CMakeFiles/TestPolymorphism.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/TestPolymorphism.dir/main.cpp.o.requires

CMakeFiles/TestPolymorphism.dir/main.cpp.o.provides: CMakeFiles/TestPolymorphism.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/TestPolymorphism.dir/build.make CMakeFiles/TestPolymorphism.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/TestPolymorphism.dir/main.cpp.o.provides

CMakeFiles/TestPolymorphism.dir/main.cpp.o.provides.build: CMakeFiles/TestPolymorphism.dir/main.cpp.o


# Object files for target TestPolymorphism
TestPolymorphism_OBJECTS = \
"CMakeFiles/TestPolymorphism.dir/main.cpp.o"

# External object files for target TestPolymorphism
TestPolymorphism_EXTERNAL_OBJECTS =

TestPolymorphism: CMakeFiles/TestPolymorphism.dir/main.cpp.o
TestPolymorphism: CMakeFiles/TestPolymorphism.dir/build.make
TestPolymorphism: CMakeFiles/TestPolymorphism.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/so/Desktop/UBB/OOP2/TestPolymorphism/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestPolymorphism"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestPolymorphism.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestPolymorphism.dir/build: TestPolymorphism

.PHONY : CMakeFiles/TestPolymorphism.dir/build

CMakeFiles/TestPolymorphism.dir/requires: CMakeFiles/TestPolymorphism.dir/main.cpp.o.requires

.PHONY : CMakeFiles/TestPolymorphism.dir/requires

CMakeFiles/TestPolymorphism.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestPolymorphism.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestPolymorphism.dir/clean

CMakeFiles/TestPolymorphism.dir/depend:
	cd /Users/so/Desktop/UBB/OOP2/TestPolymorphism/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/so/Desktop/UBB/OOP2/TestPolymorphism /Users/so/Desktop/UBB/OOP2/TestPolymorphism /Users/so/Desktop/UBB/OOP2/TestPolymorphism/cmake-build-debug /Users/so/Desktop/UBB/OOP2/TestPolymorphism/cmake-build-debug /Users/so/Desktop/UBB/OOP2/TestPolymorphism/cmake-build-debug/CMakeFiles/TestPolymorphism.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestPolymorphism.dir/depend

