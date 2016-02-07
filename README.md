project_test
============

This is a skeleton of a C++ project.
The project is using the following tools:
    
* Test Framework: Google Test
* Documentation Gen: Sphinx
* Build Tool: CMake
* Version Control System: Git
* Dependencies: CMake/Git/gitmodules
   
#  How to

## Add Source Files

## Add Tests

Compile file_test.cpp linked to libraries (gtest and -pthread are already added) using the command:

    TEST_MACRO(file libraries)

## Doc

### Sphinx versus Doxygen

### Sphinx-quickstart

### Doxygen-quickstart
    
## Add Benchmark

## Profiling

## Add Submodules i.e third party libraries
    
* open git bash
* go to the hala repo
* git submodule add url_to_dependency_repo

Example: add gtest to the project

    git submodule add https://github.com/Itseez/opencv.git dependencies/opencv

# Benchmarking tools

* how to activate optimization on CMake
* Goole Perf ?
* Nonius ? <== Need to be updated
* hayai ?

# Sanitizer Command

# Valgrind

# gdb

# Design

# Issues

* gitmodule may cause Code redundancy, nevertheless, it will mostlikely never be fixed since
the project may require a specific version of the said dependency and not the lastest version you locally have.
* Test Macro: What if *_test need specific libraries
