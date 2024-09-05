cmake_minimum_required(VERSION 3.10)

# Set the compiling mode flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -s")

# Set the project name
project(TestName) 

include_directories(include)
# Add the executable

add_executable(TestName
 src/main.c
 src/Card.c
 src/fill_deck.c
 src/fill_hand.c
 src/check_hand.c)
