#ifndef PROJECT_TEST_TESTS_MULT_HEADER
#define PROJECT_TEST_TESTS_MULT_HEADER

#include <gtest/gtest.h>

#include <Symbolic.h>

TEST(Mult, eval)
{
    auto f = sym::mult(sym::make_val(21), sym::make_val(32));
    sym::Context ctx;

    EXPECT_DOUBLE_EQ(21 * 32, f->full_eval(ctx));

    delete f;
}

// This test will fail because mult->derivate implementation is wrong
TEST(Mult, derivate)
{
    auto x = sym::make_var("x");

    auto f = sym::mult(x, sym::make_val(32));
    sym::Context ctx;

    auto deriv = f->derivate("x");

    EXPECT_DOUBLE_EQ(32, deriv->full_eval(ctx));

    delete x;
    delete f;
    delete deriv;
}


#endif

