
# compile gtest
ADD_SUBDIRECTORY(gtest)

# I don't think you will need this
SET(${BUILD_GMOCK} OFF)
SET(${BUILD_GTEST} ON)

# ADD_SUBDIRECTORY(openCV)