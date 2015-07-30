#include "stdafx.h"

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    ::testing::FLAGS_gtest_death_test_style = "*";

    return RUN_ALL_TESTS();
}

