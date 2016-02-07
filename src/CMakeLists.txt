# better way ?
INCLUDE_DIRECTORIES(.)

# Source files
# ====================================
#           (Glob is not recommended)

SET(PROJECT_TEST_HDS
    functions/my_header.h
)

SET(PROJECT_TEST_SRC
    functions/my_source.cpp
)

# main library (prevent recompilation when building tests)
ADD_LIBRARY(project_test ${PROJECT_TEST_SRC} ${PROJECT_TEST_HDS})

# main executable
ADD_EXECUTABLE(main main.cpp)
TARGET_LINK_LIBRARIES(main project_test)

# the compiler must support C++11
SET(${CXX_STANDARD_REQUIRED} ON)

SET_PROPERTY(TARGET main PROPERTY CXX_STANDARD 11)
SET_PROPERTY(TARGET project_test PROPERTY CXX_STANDARD 11)
