#ifndef VANAGANDR_TEST_EIGENDATE_HEADER
#define VANAGANDR_TEST_EIGENDATE_HEADER

#include <gtest/gtest.h>
#include "functions/my_header.h"

//TEST(square_test, test1)
//{
//    for (int i = 0; i < 20; ++i){
//        ASSERT_DOUBLE_EQ(square(i), i * i);
//    }
//}

TEST(my_function_test, test2)
{
    print_hello_world();

    ASSERT_EQ(1, my_function());
}

TEST(my_class_test, test1)
{
    print_hello_world();

    ASSERT_EQ(1, my_function());
}

TEST(my_class_test, test2)
{
    print_hello_world();

    ASSERT_EQ(1, my_function());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    return 0;
}

#endif

