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
CMAKE_SOURCE_DIR = /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/task3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/task3/build

# Include any dependencies generated for this target.
include CMakeFiles/counter_handler.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/counter_handler.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/counter_handler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/counter_handler.dir/flags.make

CMakeFiles/counter_handler.dir/src/main.c.o: CMakeFiles/counter_handler.dir/flags.make
CMakeFiles/counter_handler.dir/src/main.c.o: /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/task3/src/main.c
CMakeFiles/counter_handler.dir/src/main.c.o: CMakeFiles/counter_handler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/task3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/counter_handler.dir/src/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/counter_handler.dir/src/main.c.o -MF CMakeFiles/counter_handler.dir/src/main.c.o.d -o CMakeFiles/counter_handler.dir/src/main.c.o -c /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/task3/src/main.c

CMakeFiles/counter_handler.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/counter_handler.dir/src/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/task3/src/main.c > CMakeFiles/counter_handler.dir/src/main.c.i

CMakeFiles/counter_handler.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/counter_handler.dir/src/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/task3/src/main.c -o CMakeFiles/counter_handler.dir/src/main.c.s

CMakeFiles/counter_handler.dir/src/functions.c.o: CMakeFiles/counter_handler.dir/flags.make
CMakeFiles/counter_handler.dir/src/functions.c.o: /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/task3/src/functions.c
CMakeFiles/counter_handler.dir/src/functions.c.o: CMakeFiles/counter_handler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/task3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/counter_handler.dir/src/functions.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/counter_handler.dir/src/functions.c.o -MF CMakeFiles/counter_handler.dir/src/functions.c.o.d -o CMakeFiles/counter_handler.dir/src/functions.c.o -c /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/task3/src/functions.c

CMakeFiles/counter_handler.dir/src/functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/counter_handler.dir/src/functions.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/task3/src/functions.c > CMakeFiles/counter_handler.dir/src/functions.c.i

CMakeFiles/counter_handler.dir/src/functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/counter_handler.dir/src/functions.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/task3/src/functions.c -o CMakeFiles/counter_handler.dir/src/functions.c.s

# Object files for target counter_handler
counter_handler_OBJECTS = \
"CMakeFiles/counter_handler.dir/src/main.c.o" \
"CMakeFiles/counter_handler.dir/src/functions.c.o"

# External object files for target counter_handler
counter_handler_EXTERNAL_OBJECTS =

counter_handler: CMakeFiles/counter_handler.dir/src/main.c.o
counter_handler: CMakeFiles/counter_handler.dir/src/functions.c.o
counter_handler: CMakeFiles/counter_handler.dir/build.make
counter_handler: CMakeFiles/counter_handler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/task3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable counter_handler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/counter_handler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/counter_handler.dir/build: counter_handler
.PHONY : CMakeFiles/counter_handler.dir/build

CMakeFiles/counter_handler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/counter_handler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/counter_handler.dir/clean

CMakeFiles/counter_handler.dir/depend:
	cd /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/task3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/task3 /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/task3 /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/task3/build /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/task3/build /home/ssg/Desktop/os-labs-repo/os-labs/os-lab-2/task3/build/CMakeFiles/counter_handler.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/counter_handler.dir/depend

