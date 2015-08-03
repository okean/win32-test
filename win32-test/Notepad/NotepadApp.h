#pragma once

#include "win32-test/Application.h"
#include "GUI/MainWindow.h"

namespace WIN32TEST {

namespace Notepad {

class NotepadApp : public Application
{
public:
    NotepadApp();
    ~NotepadApp();

public:  // public typdefs
    typedef Notepad::GUI::MainWindowPtr                                 MainWindowPtr;
    typedef std::function <void(MainWindowPtr, const std::string &)>    OnLaunched;

public: // class helpers
    static void launch(OnLaunched onLaunched);
};

} // namespace Notepad
} // namespace WIN32TEST