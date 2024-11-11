cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS_DEBUG "-g -00 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-03 -DNDEBUG -s")
set(CMAKE_C_FLAGS "-std=c99")

project(task1) 

include_directories(include)
# Add the executable
add_executable(task1
 src/main.c
 src/functions.c
)