# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hjzhou/leveldb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hjzhou/leveldb

# Include any dependencies generated for this target.
include CMakeFiles/print_log.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/print_log.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/print_log.dir/flags.make

CMakeFiles/print_log.dir/test/print_log.cpp.o: CMakeFiles/print_log.dir/flags.make
CMakeFiles/print_log.dir/test/print_log.cpp.o: test/print_log.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hjzhou/leveldb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/print_log.dir/test/print_log.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/print_log.dir/test/print_log.cpp.o -c /Users/hjzhou/leveldb/test/print_log.cpp

CMakeFiles/print_log.dir/test/print_log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/print_log.dir/test/print_log.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hjzhou/leveldb/test/print_log.cpp > CMakeFiles/print_log.dir/test/print_log.cpp.i

CMakeFiles/print_log.dir/test/print_log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/print_log.dir/test/print_log.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hjzhou/leveldb/test/print_log.cpp -o CMakeFiles/print_log.dir/test/print_log.cpp.s

# Object files for target print_log
print_log_OBJECTS = \
"CMakeFiles/print_log.dir/test/print_log.cpp.o"

# External object files for target print_log
print_log_EXTERNAL_OBJECTS =

print_log: CMakeFiles/print_log.dir/test/print_log.cpp.o
print_log: CMakeFiles/print_log.dir/build.make
print_log: CMakeFiles/print_log.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hjzhou/leveldb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable print_log"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/print_log.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/print_log.dir/build: print_log

.PHONY : CMakeFiles/print_log.dir/build

CMakeFiles/print_log.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/print_log.dir/cmake_clean.cmake
.PHONY : CMakeFiles/print_log.dir/clean

CMakeFiles/print_log.dir/depend:
	cd /Users/hjzhou/leveldb && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hjzhou/leveldb /Users/hjzhou/leveldb /Users/hjzhou/leveldb /Users/hjzhou/leveldb /Users/hjzhou/leveldb/CMakeFiles/print_log.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/print_log.dir/depend

