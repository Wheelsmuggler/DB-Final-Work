# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/db_test1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/db_test1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/db_test1.dir/flags.make

CMakeFiles/db_test1.dir/test/db_test1.cc.o: CMakeFiles/db_test1.dir/flags.make
CMakeFiles/db_test1.dir/test/db_test1.cc.o: ../test/db_test1.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/db_test1.dir/test/db_test1.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/db_test1.dir/test/db_test1.cc.o -c /Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb/test/db_test1.cc

CMakeFiles/db_test1.dir/test/db_test1.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/db_test1.dir/test/db_test1.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb/test/db_test1.cc > CMakeFiles/db_test1.dir/test/db_test1.cc.i

CMakeFiles/db_test1.dir/test/db_test1.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/db_test1.dir/test/db_test1.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb/test/db_test1.cc -o CMakeFiles/db_test1.dir/test/db_test1.cc.s

# Object files for target db_test1
db_test1_OBJECTS = \
"CMakeFiles/db_test1.dir/test/db_test1.cc.o"

# External object files for target db_test1
db_test1_EXTERNAL_OBJECTS =

db_test1: CMakeFiles/db_test1.dir/test/db_test1.cc.o
db_test1: CMakeFiles/db_test1.dir/build.make
db_test1: libleveldb.a
db_test1: CMakeFiles/db_test1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable db_test1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/db_test1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/db_test1.dir/build: db_test1

.PHONY : CMakeFiles/db_test1.dir/build

CMakeFiles/db_test1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/db_test1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/db_test1.dir/clean

CMakeFiles/db_test1.dir/depend:
	cd /Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb /Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb /Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb/cmake-build-debug /Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb/cmake-build-debug /Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb/cmake-build-debug/CMakeFiles/db_test1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/db_test1.dir/depend

