#include "stdafx.h"
#include <util/Event.h>
#include <win32-test/Notepad/NotepadApp.h>
#include <win32-test/Notepad/GUI/MainWindow.h>

using namespace Util;
using namespace WIN32TEST::Notepad;
using namespace WIN32TEST::Notepad::GUI;

namespace { const unsigned int timeout = 30000; }

namespace { MainWindowPtr mainWindow{}; }

TEST(Notepad, Initialization)
{
	Event event;

    NotepadApp::launch([&](MainWindowPtr wnd, const std::string &errMsg)
    {
        EXPECT_NE(nullptr, wnd);
        EXPECT_EQ("", errMsg);

        mainWindow = wnd;

        event.set();
    });

    EXPECT_TRUE(event.wait(timeout));
}

TEST(Notepad, WriteReadText)
{
    ASSERT_NE(nullptr, mainWindow);

    const std::string input{ "Some text" };

    mainWindow->write(input);

    const std::string text{ mainWindow->read() };

    EXPECT_EQ(input, text);
}

TEST(Notepad, ReplaceAll)
{
    ASSERT_NE(nullptr, mainWindow);

    Event event;

    mainWindow->replaceAll("Some", "Any", true, [&](bool succeeded, const std::string &errMsg)
    {
        EXPECT_TRUE(succeeded);
        EXPECT_EQ("", errMsg);

        EXPECT_EQ("Any text", mainWindow->read());

        event.set();
    });

    EXPECT_TRUE(event.wait(timeout));
}

TEST(Notepad, SaveAs)
{
    Event event;

    mainWindow->saveAs("", [&](bool succeeded, const std::string &errMsg)
    {
        EXPECT_TRUE(succeeded);
        EXPECT_EQ("", errMsg);

        event.set();
    });

    EXPECT_TRUE(event.wait(timeout));
}

TEST(Notepad, Exit)
{
    ASSERT_NE(nullptr, mainWindow);

    mainWindow->exitWithoutSaving();
}