# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n_unitary

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n_unitary/build

# Include any dependencies generated for this target.
include CMakeFiles/Tests_word_n_unitary.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Tests_word_n_unitary.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Tests_word_n_unitary.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tests_word_n_unitary.dir/flags.make

CMakeFiles/Tests_word_n_unitary.dir/tests/Tests_word_n_unitary.cpp.o: CMakeFiles/Tests_word_n_unitary.dir/flags.make
CMakeFiles/Tests_word_n_unitary.dir/tests/Tests_word_n_unitary.cpp.o: /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n_unitary/tests/Tests_word_n_unitary.cpp
CMakeFiles/Tests_word_n_unitary.dir/tests/Tests_word_n_unitary.cpp.o: CMakeFiles/Tests_word_n_unitary.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n_unitary/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tests_word_n_unitary.dir/tests/Tests_word_n_unitary.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Tests_word_n_unitary.dir/tests/Tests_word_n_unitary.cpp.o -MF CMakeFiles/Tests_word_n_unitary.dir/tests/Tests_word_n_unitary.cpp.o.d -o CMakeFiles/Tests_word_n_unitary.dir/tests/Tests_word_n_unitary.cpp.o -c /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n_unitary/tests/Tests_word_n_unitary.cpp

CMakeFiles/Tests_word_n_unitary.dir/tests/Tests_word_n_unitary.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Tests_word_n_unitary.dir/tests/Tests_word_n_unitary.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n_unitary/tests/Tests_word_n_unitary.cpp > CMakeFiles/Tests_word_n_unitary.dir/tests/Tests_word_n_unitary.cpp.i

CMakeFiles/Tests_word_n_unitary.dir/tests/Tests_word_n_unitary.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Tests_word_n_unitary.dir/tests/Tests_word_n_unitary.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n_unitary/tests/Tests_word_n_unitary.cpp -o CMakeFiles/Tests_word_n_unitary.dir/tests/Tests_word_n_unitary.cpp.s

# Object files for target Tests_word_n_unitary
Tests_word_n_unitary_OBJECTS = \
"CMakeFiles/Tests_word_n_unitary.dir/tests/Tests_word_n_unitary.cpp.o"

# External object files for target Tests_word_n_unitary
Tests_word_n_unitary_EXTERNAL_OBJECTS =

Tests_word_n_unitary: CMakeFiles/Tests_word_n_unitary.dir/tests/Tests_word_n_unitary.cpp.o
Tests_word_n_unitary: CMakeFiles/Tests_word_n_unitary.dir/build.make
Tests_word_n_unitary: libWord_n_unitary_lib.so
Tests_word_n_unitary: CMakeFiles/Tests_word_n_unitary.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n_unitary/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tests_word_n_unitary"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tests_word_n_unitary.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tests_word_n_unitary.dir/build: Tests_word_n_unitary
.PHONY : CMakeFiles/Tests_word_n_unitary.dir/build

CMakeFiles/Tests_word_n_unitary.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tests_word_n_unitary.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tests_word_n_unitary.dir/clean

CMakeFiles/Tests_word_n_unitary.dir/depend:
	cd /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n_unitary/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n_unitary /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n_unitary /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n_unitary/build /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n_unitary/build /home/adrieng/Documents/Dev/C-Cpp/RSA/Word_n_unitary/build/CMakeFiles/Tests_word_n_unitary.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Tests_word_n_unitary.dir/depend

