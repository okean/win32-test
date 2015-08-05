#pragma once

#include<util/Win/GUI/Window.h>
#include <memory>

namespace WIN32TEST {
namespace Notepad {
namespace GUI {

class SaveAsWindow : public Util::Win::GUI::Window
{
public:
    SaveAsWindow(HWND hwnd);
    ~SaveAsWindow();
};

typedef std::shared_ptr<SaveAsWindow> SaveAsWindowPtr;

} // namespace GUI
} // namespace Notepad
} // namespace WIN32TEST