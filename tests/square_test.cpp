#ifndef VANAGANDR_TEST_EIGENDATE_HEADER
#define VANAGANDR_TEST_EIGENDATE_HEADER

#include <gtest/gtest.h>
#include "functions/my_header.h"

TEST(square2, int)
{
    for(int i = 0; i < 10; ++i)
        ASSERT_EQ(i * i, square2(i));
}

TEST(square2, float)
{
    for(int i = 0; i < 10; ++i){
        float g = i * 1.5;
        ASSERT_EQ(g * g, square2(g));
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    return 0;
}

#endif

