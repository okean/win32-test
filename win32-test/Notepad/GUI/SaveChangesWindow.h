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

private: // internal structs
    enum CtrlsId
    {
        dontSaveTxt
    };

private: // internal typedefs
    typedef Util::Win::GUI::Button Button;

private: // internal helpers
    static const std::string ctrlIdToString(CtrlsId id);

private: // member variables
    Button _dontSaveBtn;
};

typedef std::shared_ptr<SaveChangesWindow> SaveChangesWindowPtr;

} // namespace GUI
} // namespace Notepad
} // namespace WIN32TEST
