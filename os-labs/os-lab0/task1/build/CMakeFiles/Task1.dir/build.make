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
CMAKE_SOURCE_DIR = /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/build

# Include any dependencies generated for this target.
include CMakeFiles/Task1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Task1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Task1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task1.dir/flags.make

CMakeFiles/Task1.dir/src/main.c.o: CMakeFiles/Task1.dir/flags.make
CMakeFiles/Task1.dir/src/main.c.o: /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/src/main.c
CMakeFiles/Task1.dir/src/main.c.o: CMakeFiles/Task1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Task1.dir/src/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Task1.dir/src/main.c.o -MF CMakeFiles/Task1.dir/src/main.c.o.d -o CMakeFiles/Task1.dir/src/main.c.o -c /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/src/main.c

CMakeFiles/Task1.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Task1.dir/src/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/src/main.c > CMakeFiles/Task1.dir/src/main.c.i

CMakeFiles/Task1.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Task1.dir/src/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/src/main.c -o CMakeFiles/Task1.dir/src/main.c.s

CMakeFiles/Task1.dir/src/VerifyGuess.c.o: CMakeFiles/Task1.dir/flags.make
CMakeFiles/Task1.dir/src/VerifyGuess.c.o: /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/src/VerifyGuess.c
CMakeFiles/Task1.dir/src/VerifyGuess.c.o: CMakeFiles/Task1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Task1.dir/src/VerifyGuess.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Task1.dir/src/VerifyGuess.c.o -MF CMakeFiles/Task1.dir/src/VerifyGuess.c.o.d -o CMakeFiles/Task1.dir/src/VerifyGuess.c.o -c /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/src/VerifyGuess.c

CMakeFiles/Task1.dir/src/VerifyGuess.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Task1.dir/src/VerifyGuess.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/src/VerifyGuess.c > CMakeFiles/Task1.dir/src/VerifyGuess.c.i

CMakeFiles/Task1.dir/src/VerifyGuess.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Task1.dir/src/VerifyGuess.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/src/VerifyGuess.c -o CMakeFiles/Task1.dir/src/VerifyGuess.c.s

CMakeFiles/Task1.dir/src/GetUserGuess.c.o: CMakeFiles/Task1.dir/flags.make
CMakeFiles/Task1.dir/src/GetUserGuess.c.o: /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/src/GetUserGuess.c
CMakeFiles/Task1.dir/src/GetUserGuess.c.o: CMakeFiles/Task1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Task1.dir/src/GetUserGuess.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Task1.dir/src/GetUserGuess.c.o -MF CMakeFiles/Task1.dir/src/GetUserGuess.c.o.d -o CMakeFiles/Task1.dir/src/GetUserGuess.c.o -c /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/src/GetUserGuess.c

CMakeFiles/Task1.dir/src/GetUserGuess.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Task1.dir/src/GetUserGuess.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/src/GetUserGuess.c > CMakeFiles/Task1.dir/src/GetUserGuess.c.i

CMakeFiles/Task1.dir/src/GetUserGuess.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Task1.dir/src/GetUserGuess.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/src/GetUserGuess.c -o CMakeFiles/Task1.dir/src/GetUserGuess.c.s

CMakeFiles/Task1.dir/src/GenerateRandNumber.c.o: CMakeFiles/Task1.dir/flags.make
CMakeFiles/Task1.dir/src/GenerateRandNumber.c.o: /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/src/GenerateRandNumber.c
CMakeFiles/Task1.dir/src/GenerateRandNumber.c.o: CMakeFiles/Task1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Task1.dir/src/GenerateRandNumber.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Task1.dir/src/GenerateRandNumber.c.o -MF CMakeFiles/Task1.dir/src/GenerateRandNumber.c.o.d -o CMakeFiles/Task1.dir/src/GenerateRandNumber.c.o -c /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/src/GenerateRandNumber.c

CMakeFiles/Task1.dir/src/GenerateRandNumber.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Task1.dir/src/GenerateRandNumber.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/src/GenerateRandNumber.c > CMakeFiles/Task1.dir/src/GenerateRandNumber.c.i

CMakeFiles/Task1.dir/src/GenerateRandNumber.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Task1.dir/src/GenerateRandNumber.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/src/GenerateRandNumber.c -o CMakeFiles/Task1.dir/src/GenerateRandNumber.c.s

# Object files for target Task1
Task1_OBJECTS = \
"CMakeFiles/Task1.dir/src/main.c.o" \
"CMakeFiles/Task1.dir/src/VerifyGuess.c.o" \
"CMakeFiles/Task1.dir/src/GetUserGuess.c.o" \
"CMakeFiles/Task1.dir/src/GenerateRandNumber.c.o"

# External object files for target Task1
Task1_EXTERNAL_OBJECTS =

Task1: CMakeFiles/Task1.dir/src/main.c.o
Task1: CMakeFiles/Task1.dir/src/VerifyGuess.c.o
Task1: CMakeFiles/Task1.dir/src/GetUserGuess.c.o
Task1: CMakeFiles/Task1.dir/src/GenerateRandNumber.c.o
Task1: CMakeFiles/Task1.dir/build.make
Task1: CMakeFiles/Task1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable Task1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Task1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task1.dir/build: Task1
.PHONY : CMakeFiles/Task1.dir/build

CMakeFiles/Task1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Task1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Task1.dir/clean

CMakeFiles/Task1.dir/depend:
	cd /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1 /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1 /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/build /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/build /home/sebastian/Desktop/os-labs-repo/os-labs/os-lab0/task1/build/CMakeFiles/Task1.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Task1.dir/depend

