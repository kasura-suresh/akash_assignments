cmake_minimum_required(VERSION 3.10)  # CMake version check
project(c_cpp_assignments)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 11)            # Enable c++14 standard

# Add assign1.cpp file of project root directory as source file for assignment 1
set(ASSIGNMENT1_SOURCE assign1.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(assign1 ${ASSIGNMENT1_SOURCE})

# Add assign2.cpp file of project root directory as source file for assignment 2
set(ASSIGNMENT2_SOURCE assign2.cpp)
# Add executable target with source files listed in SOURCE_FILES variable
add_executable(assign2 ${ASSIGNMENT2_SOURCE})

# Add assign3_template.cpp file of project root directory as source file for assignment 3
set(ASSIGNMENT3_SOURCE assign3_template.cpp)
# Add executable target with source files listed in SOURCE_FILES variable
add_executable(assign3 ${ASSIGNMENT3_SOURCE})
