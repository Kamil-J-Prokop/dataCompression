# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/kamil1/Projects/dataCompressionScratch

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kamil1/Projects/dataCompressionScratch/build

# Include any dependencies generated for this target.
include fCWT/fCWT/CMakeFiles/fCWT.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include fCWT/fCWT/CMakeFiles/fCWT.dir/compiler_depend.make

# Include the progress variables for this target.
include fCWT/fCWT/CMakeFiles/fCWT.dir/progress.make

# Include the compile flags for this target's objects.
include fCWT/fCWT/CMakeFiles/fCWT.dir/flags.make

fCWT/fCWT/CMakeFiles/fCWT.dir/src/fcwt/fcwt.cpp.o: fCWT/fCWT/CMakeFiles/fCWT.dir/flags.make
fCWT/fCWT/CMakeFiles/fCWT.dir/src/fcwt/fcwt.cpp.o: ../fCWT/fCWT/src/fcwt/fcwt.cpp
fCWT/fCWT/CMakeFiles/fCWT.dir/src/fcwt/fcwt.cpp.o: fCWT/fCWT/CMakeFiles/fCWT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kamil1/Projects/dataCompressionScratch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object fCWT/fCWT/CMakeFiles/fCWT.dir/src/fcwt/fcwt.cpp.o"
	cd /home/kamil1/Projects/dataCompressionScratch/build/fCWT/fCWT && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT fCWT/fCWT/CMakeFiles/fCWT.dir/src/fcwt/fcwt.cpp.o -MF CMakeFiles/fCWT.dir/src/fcwt/fcwt.cpp.o.d -o CMakeFiles/fCWT.dir/src/fcwt/fcwt.cpp.o -c /home/kamil1/Projects/dataCompressionScratch/fCWT/fCWT/src/fcwt/fcwt.cpp

fCWT/fCWT/CMakeFiles/fCWT.dir/src/fcwt/fcwt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fCWT.dir/src/fcwt/fcwt.cpp.i"
	cd /home/kamil1/Projects/dataCompressionScratch/build/fCWT/fCWT && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kamil1/Projects/dataCompressionScratch/fCWT/fCWT/src/fcwt/fcwt.cpp > CMakeFiles/fCWT.dir/src/fcwt/fcwt.cpp.i

fCWT/fCWT/CMakeFiles/fCWT.dir/src/fcwt/fcwt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fCWT.dir/src/fcwt/fcwt.cpp.s"
	cd /home/kamil1/Projects/dataCompressionScratch/build/fCWT/fCWT && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kamil1/Projects/dataCompressionScratch/fCWT/fCWT/src/fcwt/fcwt.cpp -o CMakeFiles/fCWT.dir/src/fcwt/fcwt.cpp.s

# Object files for target fCWT
fCWT_OBJECTS = \
"CMakeFiles/fCWT.dir/src/fcwt/fcwt.cpp.o"

# External object files for target fCWT
fCWT_EXTERNAL_OBJECTS =

fCWT/fCWT/libfCWT.so.2.0: fCWT/fCWT/CMakeFiles/fCWT.dir/src/fcwt/fcwt.cpp.o
fCWT/fCWT/libfCWT.so.2.0: fCWT/fCWT/CMakeFiles/fCWT.dir/build.make
fCWT/fCWT/libfCWT.so.2.0: ../fCWT/fCWT/libs/libfftw3fl.so
fCWT/fCWT/libfCWT.so.2.0: ../fCWT/fCWT/libs/libfftw3f_ompl.so
fCWT/fCWT/libfCWT.so.2.0: fCWT/fCWT/CMakeFiles/fCWT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kamil1/Projects/dataCompressionScratch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libfCWT.so"
	cd /home/kamil1/Projects/dataCompressionScratch/build/fCWT/fCWT && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fCWT.dir/link.txt --verbose=$(VERBOSE)
	cd /home/kamil1/Projects/dataCompressionScratch/build/fCWT/fCWT && $(CMAKE_COMMAND) -E cmake_symlink_library libfCWT.so.2.0 libfCWT.so.2.0 libfCWT.so

fCWT/fCWT/libfCWT.so: fCWT/fCWT/libfCWT.so.2.0
	@$(CMAKE_COMMAND) -E touch_nocreate fCWT/fCWT/libfCWT.so

# Rule to build all files generated by this target.
fCWT/fCWT/CMakeFiles/fCWT.dir/build: fCWT/fCWT/libfCWT.so
.PHONY : fCWT/fCWT/CMakeFiles/fCWT.dir/build

fCWT/fCWT/CMakeFiles/fCWT.dir/clean:
	cd /home/kamil1/Projects/dataCompressionScratch/build/fCWT/fCWT && $(CMAKE_COMMAND) -P CMakeFiles/fCWT.dir/cmake_clean.cmake
.PHONY : fCWT/fCWT/CMakeFiles/fCWT.dir/clean

fCWT/fCWT/CMakeFiles/fCWT.dir/depend:
	cd /home/kamil1/Projects/dataCompressionScratch/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kamil1/Projects/dataCompressionScratch /home/kamil1/Projects/dataCompressionScratch/fCWT/fCWT /home/kamil1/Projects/dataCompressionScratch/build /home/kamil1/Projects/dataCompressionScratch/build/fCWT/fCWT /home/kamil1/Projects/dataCompressionScratch/build/fCWT/fCWT/CMakeFiles/fCWT.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : fCWT/fCWT/CMakeFiles/fCWT.dir/depend
