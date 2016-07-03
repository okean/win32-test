#include "stdafx.h"

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    ::testing::GTEST_FLAG(output) = "xml:automated-tests.xml";

    ::testing::FLAGS_gtest_filter = "Notepad.Initialization:"
                                    "Notepad.WriteReadText:"
                                    "Notepad.ReplaceAll:"
                                    "Notepad.SetPageOrientation:"
                                    "Notepad.Exit";

    return RUN_ALL_TESTS();
}
