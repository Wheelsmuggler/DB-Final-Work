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
include CMakeFiles/skiplist_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/skiplist_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/skiplist_test.dir/flags.make

CMakeFiles/skiplist_test.dir/util/testutil.cc.o: CMakeFiles/skiplist_test.dir/flags.make
CMakeFiles/skiplist_test.dir/util/testutil.cc.o: ../util/testutil.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/skiplist_test.dir/util/testutil.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/skiplist_test.dir/util/testutil.cc.o -c /Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb/util/testutil.cc

CMakeFiles/skiplist_test.dir/util/testutil.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/skiplist_test.dir/util/testutil.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb/util/testutil.cc > CMakeFiles/skiplist_test.dir/util/testutil.cc.i

CMakeFiles/skiplist_test.dir/util/testutil.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/skiplist_test.dir/util/testutil.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb/util/testutil.cc -o CMakeFiles/skiplist_test.dir/util/testutil.cc.s

CMakeFiles/skiplist_test.dir/db/skiplist_test.cc.o: CMakeFiles/skiplist_test.dir/flags.make
CMakeFiles/skiplist_test.dir/db/skiplist_test.cc.o: ../db/skiplist_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/skiplist_test.dir/db/skiplist_test.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/skiplist_test.dir/db/skiplist_test.cc.o -c /Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb/db/skiplist_test.cc

CMakeFiles/skiplist_test.dir/db/skiplist_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/skiplist_test.dir/db/skiplist_test.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb/db/skiplist_test.cc > CMakeFiles/skiplist_test.dir/db/skiplist_test.cc.i

CMakeFiles/skiplist_test.dir/db/skiplist_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/skiplist_test.dir/db/skiplist_test.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb/db/skiplist_test.cc -o CMakeFiles/skiplist_test.dir/db/skiplist_test.cc.s

# Object files for target skiplist_test
skiplist_test_OBJECTS = \
"CMakeFiles/skiplist_test.dir/util/testutil.cc.o" \
"CMakeFiles/skiplist_test.dir/db/skiplist_test.cc.o"

# External object files for target skiplist_test
skiplist_test_EXTERNAL_OBJECTS =

skiplist_test: CMakeFiles/skiplist_test.dir/util/testutil.cc.o
skiplist_test: CMakeFiles/skiplist_test.dir/db/skiplist_test.cc.o
skiplist_test: CMakeFiles/skiplist_test.dir/build.make
skiplist_test: libleveldb.a
skiplist_test: lib/libgmockd.a
skiplist_test: lib/libgtestd.a
skiplist_test: CMakeFiles/skiplist_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable skiplist_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/skiplist_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/skiplist_test.dir/build: skiplist_test

.PHONY : CMakeFiles/skiplist_test.dir/build

CMakeFiles/skiplist_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/skiplist_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/skiplist_test.dir/clean

CMakeFiles/skiplist_test.dir/depend:
	cd /Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb /Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb /Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb/cmake-build-debug /Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb/cmake-build-debug /Users/anthonymao08/Documents/School/DataSystem/courseforleveldb/leveldb/cmake-build-debug/CMakeFiles/skiplist_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/skiplist_test.dir/depend

