#cmake_minimum_required(VERSION 3.10)  # CMake version check
#project(c_cpp_assignments)               # Create project "simple_example"
#set(CMAKE_CXX_STANDARD 11)            # Enable c++14 standard

# Add assign1.cpp file of project root directory as source file for assignment 1
set(ASSIGNMENT1_SOURCE structure-class.cpp)
# Add executable target with source files listed in SOURCE_FILES variable
add_executable(assign1 ${ASSIGNMENT1_SOURCE})

# Add assign2.cpp file of project root directory as source file for assignment 2
set(ASSIGNMENT2_SOURCE structure-class-inherit.cpp)
# Add executable target with source files listed in SOURCE_FILES variable
add_executable(assign2 ${ASSIGNMENT2_SOURCE})

set(ASSIGNMENT3_SOURCE copy-constructor.cpp)
add_executable(assign3 ${ASSIGNMENT3_SOURCE})

set(ASSIGNMENT4_SOURCE Operator_overloading.cpp)
add_executable(assign4 ${ASSIGNMENT4_SOURCE})


set(ASSIGNMENT5_SOURCE para-constructor.cpp)
add_executable(assign5 ${ASSIGNMENT5_SOURCE})


set(ASSIGNMENT6_SOURCE singleton.cpp)
add_executable(assign6 ${ASSIGNMENT6_SOURCE})


set(ASSIGNMENT7_SOURCE multilevel.cpp)
add_executable(assign7 ${ASSIGNMENT7_SOURCE})


set(ASSIGNMENT8_SOURCE multiple.cpp)
add_executable(assign8 ${ASSIGNMENT8_SOURCE})


set(ASSIGNMENT9_SOURCE ostream.cpp)
add_executable(assign9 ${ASSIGNMENT9_SOURCE})


set(ASSIGNMENT10_SOURCE virtual.cpp)
add_executable(assign10 ${ASSIGNMENT10_SOURCE})


set(ASSIGNMENT11_SOURCE template.cpp)
add_executable(assign11 ${ASSIGNMENT11_SOURCE})


set(ASSIGNMENT12_SOURCE template-function.cpp)
add_executable(assign12 ${ASSIGNMENT12_SOURCE})


set(ASSIGNMENT13_SOURCE linked-list.cpp)
add_executable(assign13 ${ASSIGNMENT13_SOURCE})


set(ASSIGNMENT14_SOURCE stack.cpp)
add_executable(assign14 ${ASSIGNMENT14_SOURCE})


set(ASSIGNMENT15_SOURCE queue.cpp)
add_executable(assign15 ${ASSIGNMENT15_SOURCE})


set(ASSIGNMENT16_SOURCE circular.cpp)
add_executable(assign16 ${ASSIGNMENT16_SOURCE})


set(ASSIGNMENT17_SOURCE typecasting.cpp)
add_executable(assign17 ${ASSIGNMENT17_SOURCE})

set(ASSIGNMENT18_SOURCE explicit.cpp)
add_executable(assign18 ${ASSIGNMENT18_SOURCE})

set(ASSIGNMENT19_SOURCE interface.cpp)
add_executable(assign19 ${ASSIGNMENT19_SOURCE})

set(ASSIGNMENT20_SOURCE dynamic.cpp)
add_executable(assign20 ${ASSIGNMENT20_SOURCE})

set(ASSIGNMENT21_SOURCE object-slicing.cpp)
add_executable(assign21 ${ASSIGNMENT21_SOURCE})


set(ASSIGNMENT22_SOURCE virtual-destructor.cpp)
add_executable(assign22 ${ASSIGNMENT22_SOURCE})

