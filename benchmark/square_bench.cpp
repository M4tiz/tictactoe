#ifndef VANAGANDR_BENCH_EIGENDATE_HEADER
#define VANAGANDR_BENCH_EIGENDATE_HEADER

#include <hayai.hpp>
#include "functions/my_header.h"


BENCHMARK(Math, SquareFunction, 10, 10000)
{
    for(int i = 0; i < 10; ++i)
        square2(i);
}

BENCHMARK(Math, SquareBaseLine, 10, 10000)
{
    for(int i = 0; i < 10; ++i)
        i * i;
}

#endif

