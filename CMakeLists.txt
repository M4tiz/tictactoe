# required for C++11 features
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# project name + language used
PROJECT(project_test CXX)

# debug/release
SET(CMAKE_RELEASE_POSTFIX "")       # Release is the default
SET(CMAKE_DEBUG_POSTFIX "-debug")

# Compiler-flag
IF(${CMAKE_BUILD_TYPE} MATCHES "Debug")
    MESSAGE(STATUS "Building Debug Version")
ELSE()
    MESSAGE(STATUS "Building Release Version")
    # ADD_DEFINITIONS(-O2)                        # CMake Release is O3 by default
ENDIF()

# specify where compiled files must go
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# add cmake FindXXX script to find pre-compiled libraries if any
LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")


#
#   Cross compiling option
#   CMAKE_CROSSCOMPILING true
#   CMAKE_SYSTEM_NAME   Linux Mac Windows
#   CMAKE_SYSTEM_VERSION
#   CMAKE_SYSTEM_PROCESSOR
#   CMAKE_C_COMPILER
#   CMAKE_CXX_COMPILER

# Once the system and the compiler are determined by CMake, it loads the corresponding files in the following order:

#Platform/${CMAKE_SYSTEM_NAME}.cmake (optional, but issues a stern warning)    #Platform/${CMAKE_SYSTEM_NAME}-<compiler>.cmake (optional)
#Platform/${CMAKE_SYSTEM_NAME}-<compiler>-${CMAKE_SYSTEM_PROCESSOR}.cmake (optional)


# C++ Standard
# ====================================

SET(${CXX_STANDARD_REQUIRED} ON)    # Comment out if C++11 is not mendatory

# Project's Options
# ====================================

OPTION(BUILD_TESTING        "Enable tests"       ON)
OPTION(BUILD_BENCHMARK      "Build Benchmarks"   ON)
OPTION(BUILD_EXAMPLES       "Build Examples"     ON)
OPTION(BUILD_DOCUMENTATION  "Build docs"         OFF)
OPTION(BUILD_DOXYGEN        "Build Doxygen docs" ON)
OPTION(BUILD_SPHINX         "Build Sphinx docs"  ON)

# Binary/pre-compiled Dependencies
# ====================================

FIND_PACKAGE(Git REQUIRED)
# FIND_PACKAGE(...)


# Subdirectories
# ====================================

# Find revision ID and hash of the sourcetree
INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR})
INCLUDE(cmake/genrev.cmake)

# Dependencies to be compiled
ADD_SUBDIRECTORY(dependencies)

# How to compile main lib
ADD_SUBDIRECTORY(src)

# Compile tests ?
IF(BUILD_TESTING)
    ENABLE_TESTING()

    MESSAGE(STATUS "Building tests")
    ADD_SUBDIRECTORY(tests)
ENDIF(BUILD_TESTING)

IF (BUILD_EXAMPLES)
    MESSAGE(STATUS "Building examples")
    ADD_SUBDIRECTORY(examples)
ENDIF (BUILD_EXAMPLES)

IF (BUILD_BENCHMARK)
    MESSAGE(STATUS "Building Benchmarks")
    ADD_SUBDIRECTORY(benchmark)
ENDIF(BUILD_BENCHMARK)

# Gen doc ?
IF (BUILD_DOCUMENTATION)
    MESSAGE(STATUS "Documentation building is enabled")
    ADD_SUBDIRECTORY(docs)
ENDIF (BUILD_DOCUMENTATION)


