cmake_minimum_required(VERSION 2.8)

# Set the compiling mode flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -s")
set(CMAKE_FLAGS "-std=gnu99")
# Set the project name
project(reader) 

include_directories(include)
# Add the executable

add_executable(reader
 src/main.c
 src/functions.c)
