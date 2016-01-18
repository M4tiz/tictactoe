INCLUDE_DIRECTORIES(.)

SET(PROJECT_TEST_HDS
    functions/my_header.h
    math.h)

SET(PROJECT_TEST_SRC
    math.cpp
    functions/my_source.cpp)
    
ADD_LIBRARY(project_test ${PROJECT_TEST_SRC} ${PROJECT_TEST_HDS})

ADD_EXECUTABLE(main main.cpp)
TARGET_LINK_LIBRARIES(main project_test)

# the compiler must support C++11
SET(${CXX_STANDARD_REQUIRED} ON)
SET_PROPERTY(TARGET main PROPERTY CXX_STANDARD 11)
SET_PROPERTY(TARGET project_test PROPERTY CXX_STANDARD 11)
