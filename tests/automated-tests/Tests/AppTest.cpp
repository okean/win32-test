#include "stdafx.h"
#include <util/Event.h>
#include <win32-test/Notepad/NotepadApp.h>
#include <win32-test/Notepad/GUI/MainWindow.h>

using namespace Util;
using namespace WIN32TEST::Notepad;
using namespace WIN32TEST::Notepad::GUI;

namespace { const unsigned int timeout = 30000; }

TEST(Application, Initialization)
{
	Event event;

    NotepadApp::launch([&](MainWindowPtr mainWindow, const std::string &errMsg)
    {
        EXPECT_NE(nullptr, mainWindow);
        EXPECT_EQ("", errMsg);

        event.set();
    });

    EXPECT_TRUE(event.wait(timeout));
}