# CMakeLists.txt for the Word_n_unitary project

# Specify the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(Word_n_unitary)

# Specify that we are using C++17
set(CMAKE_CXX_STANDARD 17)



# Add the 'include' directory to search for public header files
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add library sources
set(LIBRARY_SOURCES
    src/Word_n_unitary.cpp
)



# Create a shared library
add_library(Word_n_unitary_lib SHARED ${LIBRARY_SOURCES})

# Set the library's public headers
# This makes sure that when other projects link to this library, they can access the headers
target_include_directories(Word_n_unitary_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)



# Enable testing
enable_testing()

# Add tests
add_executable(Tests_word_n_unitary tests/Tests_word_n_unitary.cpp)

# Link the library to the tests
target_link_libraries(Tests_word_n_unitary Word_n_unitary_lib)
