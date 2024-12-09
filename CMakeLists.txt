# CMakeLists.txt for the Word_n_unitary project

# Specify the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(Word_n_unitary)

# Specify that we are using C++17
set(CMAKE_CXX_STANDARD 17)

# Add the 'include' directory to search for header files
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add source files
set(SOURCES
    src/Main.cpp
    src/Word_n_unitary.cpp
)

# Create an executable
add_executable(Word_n_unitary ${SOURCES})

# Enable testing
enable_testing()

# Add tests
add_executable(Tests_word_n_unitary tests/Tests_word_n_unitary.cpp ${SOURCES})
