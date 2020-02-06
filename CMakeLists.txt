cmake_minimum_required(VERSION 3.10)  # CMake version check
project(c_cpp_assignments)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 11)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
set(ASSIGNMENT1_SOURCE assign1.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(assign1 ${ASSIGNMENT1_SOURCE})
