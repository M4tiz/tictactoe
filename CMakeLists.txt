# required for C++11 features
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# project name + language used
PROJECT(project_test CXX)

# debug/release
SET(CMAKE_RELEASE_POSTFIX "")
SET(CMAKE_DEBUG_POSTFIX "-debug")

# specify where compiled files must go
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# add cmake FindXXX script to find pre-compiled libraries if any
LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Project's Options
# ====================================

OPTION(BUILD_TESTING        "Enable tests"       ON)
OPTION(BUILD_DOCUMENTATION  "Build docs"         ON)
OPTION(BUILD_DOXYGEN        "Build Doxygen docs" ON)
OPTION(BUILD_SPHINX         "Build Sphinx docs"  ON)

# Binary/pre-compiled Dependencies
# ====================================

FIND_PACKAGE(Git REQUIRED)
# FIND_PACKAGE(Sphinx REQUIRED)
# FIND_PACKAGE(Sphinx REQUIRED)

# Subdirectories
# ====================================

# Find revision ID and hash of the sourcetree
include(cmake/genrev.cmake)

# Dependencies to be compiled
ADD_SUBDIRECTORY(dependencies)

# How to compile main lib
ADD_SUBDIRECTORY(src)

# Compile tests ?
IF(BUILD_TESTING)
    # compile tests
    ENABLE_TESTING()

    MESSAGE("-- Building tests")
    ADD_SUBDIRECTORY(tests)
ENDIF(BUILD_TESTING)

ADD_SUBDIRECTORY(benchmark)

# Gen doc ?
IF (BUILD_DOCUMENTATION)
    MESSAGE("-- Documentation building is enabled")
    ADD_SUBDIRECTORY(docs)
ENDIF (BUILD_DOCUMENTATION)


