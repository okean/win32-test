#include "stdafx.h"

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    ::testing::FLAGS_gtest_filter = "Notepad.Initialization:"
                                    "Notepad.WriteReadText:"
                                    "Notepad.Exit";

    return RUN_ALL_TESTS();
}
