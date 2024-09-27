cmake_minimum_required(VERSION 3.10)

# Set the compiling mode flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -s")

# Set the project name
project(task5) 

include_directories(include)
# Add the executable

add_executable(task5
 src/main.c
 src/functions.c)

 target_link_libraries(task5
    ncurses)
