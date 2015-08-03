#pragma once

#include<util/Win/GUI/Window.h>
#include <memory>

namespace WIN32TEST {
namespace Notepad {
namespace GUI {

class MainWindow : Util::Win::GUI::Window
{
public:
    MainWindow(HWND hwnd, HANDLE process);
    ~MainWindow();

private: // member variables
    HANDLE _process;
};

typedef std::shared_ptr<MainWindow> MainWindowPtr;

} // namespace GUI
} // namespace Notepad
} // namespace WIN32TEST