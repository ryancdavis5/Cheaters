# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\ryan7\CLionProjects\cheaters

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ryan7\CLionProjects\cheaters\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cheaters.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cheaters.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cheaters.dir/flags.make

CMakeFiles/cheaters.dir/main.cpp.obj: CMakeFiles/cheaters.dir/flags.make
CMakeFiles/cheaters.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ryan7\CLionProjects\cheaters\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cheaters.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\cheaters.dir\main.cpp.obj -c C:\Users\ryan7\CLionProjects\cheaters\main.cpp

CMakeFiles/cheaters.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cheaters.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ryan7\CLionProjects\cheaters\main.cpp > CMakeFiles\cheaters.dir\main.cpp.i

CMakeFiles/cheaters.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cheaters.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ryan7\CLionProjects\cheaters\main.cpp -o CMakeFiles\cheaters.dir\main.cpp.s

# Object files for target cheaters
cheaters_OBJECTS = \
"CMakeFiles/cheaters.dir/main.cpp.obj"

# External object files for target cheaters
cheaters_EXTERNAL_OBJECTS =

cheaters.exe: CMakeFiles/cheaters.dir/main.cpp.obj
cheaters.exe: CMakeFiles/cheaters.dir/build.make
cheaters.exe: CMakeFiles/cheaters.dir/linklibs.rsp
cheaters.exe: CMakeFiles/cheaters.dir/objects1.rsp
cheaters.exe: CMakeFiles/cheaters.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\ryan7\CLionProjects\cheaters\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cheaters.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\cheaters.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cheaters.dir/build: cheaters.exe

.PHONY : CMakeFiles/cheaters.dir/build

CMakeFiles/cheaters.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cheaters.dir\cmake_clean.cmake
.PHONY : CMakeFiles/cheaters.dir/clean

CMakeFiles/cheaters.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\ryan7\CLionProjects\cheaters C:\Users\ryan7\CLionProjects\cheaters C:\Users\ryan7\CLionProjects\cheaters\cmake-build-debug C:\Users\ryan7\CLionProjects\cheaters\cmake-build-debug C:\Users\ryan7\CLionProjects\cheaters\cmake-build-debug\CMakeFiles\cheaters.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cheaters.dir/depend
