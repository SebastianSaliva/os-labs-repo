# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/infinite_counter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/infinite_counter/build

# Include any dependencies generated for this target.
include CMakeFiles/infinite_counter.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/infinite_counter.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/infinite_counter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/infinite_counter.dir/flags.make

CMakeFiles/infinite_counter.dir/src/main.c.o: CMakeFiles/infinite_counter.dir/flags.make
CMakeFiles/infinite_counter.dir/src/main.c.o: /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/infinite_counter/src/main.c
CMakeFiles/infinite_counter.dir/src/main.c.o: CMakeFiles/infinite_counter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/infinite_counter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/infinite_counter.dir/src/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/infinite_counter.dir/src/main.c.o -MF CMakeFiles/infinite_counter.dir/src/main.c.o.d -o CMakeFiles/infinite_counter.dir/src/main.c.o -c /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/infinite_counter/src/main.c

CMakeFiles/infinite_counter.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/infinite_counter.dir/src/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/infinite_counter/src/main.c > CMakeFiles/infinite_counter.dir/src/main.c.i

CMakeFiles/infinite_counter.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/infinite_counter.dir/src/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/infinite_counter/src/main.c -o CMakeFiles/infinite_counter.dir/src/main.c.s

CMakeFiles/infinite_counter.dir/src/functions.c.o: CMakeFiles/infinite_counter.dir/flags.make
CMakeFiles/infinite_counter.dir/src/functions.c.o: /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/infinite_counter/src/functions.c
CMakeFiles/infinite_counter.dir/src/functions.c.o: CMakeFiles/infinite_counter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/infinite_counter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/infinite_counter.dir/src/functions.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/infinite_counter.dir/src/functions.c.o -MF CMakeFiles/infinite_counter.dir/src/functions.c.o.d -o CMakeFiles/infinite_counter.dir/src/functions.c.o -c /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/infinite_counter/src/functions.c

CMakeFiles/infinite_counter.dir/src/functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/infinite_counter.dir/src/functions.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/infinite_counter/src/functions.c > CMakeFiles/infinite_counter.dir/src/functions.c.i

CMakeFiles/infinite_counter.dir/src/functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/infinite_counter.dir/src/functions.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/infinite_counter/src/functions.c -o CMakeFiles/infinite_counter.dir/src/functions.c.s

# Object files for target infinite_counter
infinite_counter_OBJECTS = \
"CMakeFiles/infinite_counter.dir/src/main.c.o" \
"CMakeFiles/infinite_counter.dir/src/functions.c.o"

# External object files for target infinite_counter
infinite_counter_EXTERNAL_OBJECTS =

infinite_counter: CMakeFiles/infinite_counter.dir/src/main.c.o
infinite_counter: CMakeFiles/infinite_counter.dir/src/functions.c.o
infinite_counter: CMakeFiles/infinite_counter.dir/build.make
infinite_counter: CMakeFiles/infinite_counter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/infinite_counter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable infinite_counter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/infinite_counter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/infinite_counter.dir/build: infinite_counter
.PHONY : CMakeFiles/infinite_counter.dir/build

CMakeFiles/infinite_counter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/infinite_counter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/infinite_counter.dir/clean

CMakeFiles/infinite_counter.dir/depend:
	cd /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/infinite_counter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/infinite_counter /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/infinite_counter /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/infinite_counter/build /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/infinite_counter/build /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/infinite_counter/build/CMakeFiles/infinite_counter.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/infinite_counter.dir/depend

