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

# add cmake FindXXX script to find libraries if any
LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# How to compile dependencies
ADD_SUBDIRECTORY(dependencies)

# How to compile main lib
ADD_SUBDIRECTORY(src)

# Compile tests ?
# =============
OPTION(BUILD_TESTING "Enable tests" ON)

IF(BUILD_TESTING)
    # compile tests
    ENABLE_TESTING()

    MESSAGE("-- Building tests")
    ADD_SUBDIRECTORY(tests)
ENDIF(BUILD_TESTING)

# Gen doc ?
# =============
OPTION(BUILD_DOCUMENTATION "Build docs" ON)

IF (BUILD_DOCUMENTATION)
  MESSAGE("-- Documentation building is enabled")
  ADD_SUBDIRECTORY(docs)
ENDIF (BUILD_DOCUMENTATION)


