

# I am not sure we need this
INCLUDE_DIRECTORIES(../src)
INCLUDE_DIRECTORIES(${gtest_dir})
INCLUDE_DIRECTORIES(${gtest_dir}/include/)

# Add your test to CMAKE
# to run all tests run 'make test'
MACRO(CBTEST_MACRO NAME)
    ADD_EXECUTABLE(${NAME}_test ${NAME}_test.cpp )
    TARGET_LINK_LIBRARIES(${NAME}_test project_test gtest -pthread)
    ADD_TEST(NAME ${NAME}_test
        COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${NAME}_test)
ENDMACRO(CBTEST_MACRO)

# add test here
# file_name_test.cpp ==> CBTEST_MACRO(file_name)
CBTEST_MACRO(my_test)

