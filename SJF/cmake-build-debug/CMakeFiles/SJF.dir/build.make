# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/angeloalies/Documents/Operating-Systems/SJF

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/angeloalies/Documents/Operating-Systems/SJF/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SJF.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SJF.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SJF.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SJF.dir/flags.make

CMakeFiles/SJF.dir/SJF.cpp.o: CMakeFiles/SJF.dir/flags.make
CMakeFiles/SJF.dir/SJF.cpp.o: ../SJF.cpp
CMakeFiles/SJF.dir/SJF.cpp.o: CMakeFiles/SJF.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/angeloalies/Documents/Operating-Systems/SJF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SJF.dir/SJF.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SJF.dir/SJF.cpp.o -MF CMakeFiles/SJF.dir/SJF.cpp.o.d -o CMakeFiles/SJF.dir/SJF.cpp.o -c /Users/angeloalies/Documents/Operating-Systems/SJF/SJF.cpp

CMakeFiles/SJF.dir/SJF.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SJF.dir/SJF.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/angeloalies/Documents/Operating-Systems/SJF/SJF.cpp > CMakeFiles/SJF.dir/SJF.cpp.i

CMakeFiles/SJF.dir/SJF.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SJF.dir/SJF.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/angeloalies/Documents/Operating-Systems/SJF/SJF.cpp -o CMakeFiles/SJF.dir/SJF.cpp.s

# Object files for target SJF
SJF_OBJECTS = \
"CMakeFiles/SJF.dir/SJF.cpp.o"

# External object files for target SJF
SJF_EXTERNAL_OBJECTS =

SJF: CMakeFiles/SJF.dir/SJF.cpp.o
SJF: CMakeFiles/SJF.dir/build.make
SJF: CMakeFiles/SJF.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/angeloalies/Documents/Operating-Systems/SJF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SJF"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SJF.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SJF.dir/build: SJF
.PHONY : CMakeFiles/SJF.dir/build

CMakeFiles/SJF.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SJF.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SJF.dir/clean

CMakeFiles/SJF.dir/depend:
	cd /Users/angeloalies/Documents/Operating-Systems/SJF/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/angeloalies/Documents/Operating-Systems/SJF /Users/angeloalies/Documents/Operating-Systems/SJF /Users/angeloalies/Documents/Operating-Systems/SJF/cmake-build-debug /Users/angeloalies/Documents/Operating-Systems/SJF/cmake-build-debug /Users/angeloalies/Documents/Operating-Systems/SJF/cmake-build-debug/CMakeFiles/SJF.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SJF.dir/depend

