cmake_minimum_required(VERSION 3.10)

# Set the compiling mode flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -s")

# Set the project name
project(the_universe) 

include_directories(include)
# Add the executable

find_package(ALSA REQUIRED)

add_executable(the_universe
 src/main.c
 src/functions.c
 src/playtone.c)

 target_link_libraries(the_universe
 PRIVATE ALSA::ALSA 
 ncurses
 m)