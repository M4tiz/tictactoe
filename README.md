project_test
============

This is skeleton of a C++ project using CMake.
The project is using the following tools:
    
* Test Framework: Google Test
* Documentation Gen: Sphinx
* Build Tool: CMake
* Version Vontrol System: Git
* Dependencies: Git/gitmodules
    
#  How to

## Add Source Files

## Add Tests

* 
    
## Add Benchmark

## Profiling

## Add Submodules i.e third party libraries
    
* open git bash
* go to the hala repo
* git submodule add url_to_dependency_repo

Example: add OpenCV to the project

    git submodule add https://github.com/Itseez/opencv.git


# Doxygen (untested)

    find_package(Doxygen)
    if(DOXYGEN_FOUND)
        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
        add_custom_target(doc ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                COMMENT "Generating API documentation with Doxygen" VERBATIM
        )
    endif(DOXYGEN_FOUND)

from https://majewsky.wordpress.com/2010/08/14/tip-of-the-day-cmake-and-doxygen/

# Benchmarking tools

*Goole Perf ?
*Nonius ?
*hayai ?


# Issues

* gitmodule may cause Code redundancy, nevertheless, it will mostlikely never be fixed since
the project may require a specific version of the said dependency and not the lastest version you locally have.

