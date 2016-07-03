#include "stdafx.h"

int main(int argc, char** argv)
{
    ::testing::GTEST_FLAG(output) = "xml:unit-tests.xml";

    ::testing::InitGoogleTest(&argc, argv);

    ::testing::FLAGS_gtest_filter = "*";

    return RUN_ALL_TESTS();
}

