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
CMAKE_SOURCE_DIR = /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/build

# Include any dependencies generated for this target.
include CMakeFiles/TestName.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TestName.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TestName.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestName.dir/flags.make

CMakeFiles/TestName.dir/src/main.c.o: CMakeFiles/TestName.dir/flags.make
CMakeFiles/TestName.dir/src/main.c.o: /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/src/main.c
CMakeFiles/TestName.dir/src/main.c.o: CMakeFiles/TestName.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TestName.dir/src/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/TestName.dir/src/main.c.o -MF CMakeFiles/TestName.dir/src/main.c.o.d -o CMakeFiles/TestName.dir/src/main.c.o -c /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/src/main.c

CMakeFiles/TestName.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/TestName.dir/src/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/src/main.c > CMakeFiles/TestName.dir/src/main.c.i

CMakeFiles/TestName.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/TestName.dir/src/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/src/main.c -o CMakeFiles/TestName.dir/src/main.c.s

CMakeFiles/TestName.dir/src/Card.c.o: CMakeFiles/TestName.dir/flags.make
CMakeFiles/TestName.dir/src/Card.c.o: /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/src/Card.c
CMakeFiles/TestName.dir/src/Card.c.o: CMakeFiles/TestName.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/TestName.dir/src/Card.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/TestName.dir/src/Card.c.o -MF CMakeFiles/TestName.dir/src/Card.c.o.d -o CMakeFiles/TestName.dir/src/Card.c.o -c /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/src/Card.c

CMakeFiles/TestName.dir/src/Card.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/TestName.dir/src/Card.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/src/Card.c > CMakeFiles/TestName.dir/src/Card.c.i

CMakeFiles/TestName.dir/src/Card.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/TestName.dir/src/Card.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/src/Card.c -o CMakeFiles/TestName.dir/src/Card.c.s

CMakeFiles/TestName.dir/src/fill_deck.c.o: CMakeFiles/TestName.dir/flags.make
CMakeFiles/TestName.dir/src/fill_deck.c.o: /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/src/fill_deck.c
CMakeFiles/TestName.dir/src/fill_deck.c.o: CMakeFiles/TestName.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/TestName.dir/src/fill_deck.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/TestName.dir/src/fill_deck.c.o -MF CMakeFiles/TestName.dir/src/fill_deck.c.o.d -o CMakeFiles/TestName.dir/src/fill_deck.c.o -c /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/src/fill_deck.c

CMakeFiles/TestName.dir/src/fill_deck.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/TestName.dir/src/fill_deck.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/src/fill_deck.c > CMakeFiles/TestName.dir/src/fill_deck.c.i

CMakeFiles/TestName.dir/src/fill_deck.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/TestName.dir/src/fill_deck.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/src/fill_deck.c -o CMakeFiles/TestName.dir/src/fill_deck.c.s

CMakeFiles/TestName.dir/src/fill_hand.c.o: CMakeFiles/TestName.dir/flags.make
CMakeFiles/TestName.dir/src/fill_hand.c.o: /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/src/fill_hand.c
CMakeFiles/TestName.dir/src/fill_hand.c.o: CMakeFiles/TestName.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/TestName.dir/src/fill_hand.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/TestName.dir/src/fill_hand.c.o -MF CMakeFiles/TestName.dir/src/fill_hand.c.o.d -o CMakeFiles/TestName.dir/src/fill_hand.c.o -c /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/src/fill_hand.c

CMakeFiles/TestName.dir/src/fill_hand.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/TestName.dir/src/fill_hand.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/src/fill_hand.c > CMakeFiles/TestName.dir/src/fill_hand.c.i

CMakeFiles/TestName.dir/src/fill_hand.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/TestName.dir/src/fill_hand.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/src/fill_hand.c -o CMakeFiles/TestName.dir/src/fill_hand.c.s

CMakeFiles/TestName.dir/src/check_hand.c.o: CMakeFiles/TestName.dir/flags.make
CMakeFiles/TestName.dir/src/check_hand.c.o: /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/src/check_hand.c
CMakeFiles/TestName.dir/src/check_hand.c.o: CMakeFiles/TestName.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/TestName.dir/src/check_hand.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/TestName.dir/src/check_hand.c.o -MF CMakeFiles/TestName.dir/src/check_hand.c.o.d -o CMakeFiles/TestName.dir/src/check_hand.c.o -c /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/src/check_hand.c

CMakeFiles/TestName.dir/src/check_hand.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/TestName.dir/src/check_hand.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/src/check_hand.c > CMakeFiles/TestName.dir/src/check_hand.c.i

CMakeFiles/TestName.dir/src/check_hand.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/TestName.dir/src/check_hand.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/src/check_hand.c -o CMakeFiles/TestName.dir/src/check_hand.c.s

# Object files for target TestName
TestName_OBJECTS = \
"CMakeFiles/TestName.dir/src/main.c.o" \
"CMakeFiles/TestName.dir/src/Card.c.o" \
"CMakeFiles/TestName.dir/src/fill_deck.c.o" \
"CMakeFiles/TestName.dir/src/fill_hand.c.o" \
"CMakeFiles/TestName.dir/src/check_hand.c.o"

# External object files for target TestName
TestName_EXTERNAL_OBJECTS =

TestName: CMakeFiles/TestName.dir/src/main.c.o
TestName: CMakeFiles/TestName.dir/src/Card.c.o
TestName: CMakeFiles/TestName.dir/src/fill_deck.c.o
TestName: CMakeFiles/TestName.dir/src/fill_hand.c.o
TestName: CMakeFiles/TestName.dir/src/check_hand.c.o
TestName: CMakeFiles/TestName.dir/build.make
TestName: CMakeFiles/TestName.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable TestName"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestName.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestName.dir/build: TestName
.PHONY : CMakeFiles/TestName.dir/build

CMakeFiles/TestName.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestName.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestName.dir/clean

CMakeFiles/TestName.dir/depend:
	cd /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3 /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3 /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/build /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/build /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task3/build/CMakeFiles/TestName.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/TestName.dir/depend

