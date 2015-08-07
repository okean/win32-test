#pragma once

#include <util/Win/GUI/Window.h>
#include <util/Win/GUI/Button.h>
#include <memory>

namespace WIN32TEST {
namespace Notepad {
namespace GUI {

class SaveChangesWindow : public Util::Win::GUI::Window
{
public:
    SaveChangesWindow(HWND hwnd);
    ~SaveChangesWindow();

public:  // interface
    void dontSave();

private: // internal typedefs
    typedef Util::Win::GUI::Button Button;

private: // member variables
    Button _dontSaveBtn;
};

typedef std::shared_ptr<SaveChangesWindow> SaveChangesWindowPtr;

} // namespace GUI
} // namespace Notepad
} // namespace WIN32TEST