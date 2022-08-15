#include "mult_test.h"
#include "add_test.h"
#include "game_test.h"
#include "game_runner_test.h"


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
