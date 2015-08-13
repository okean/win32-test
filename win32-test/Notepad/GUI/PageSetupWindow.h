#pragma once

#include <util/Win/GUI/Window.h>
#include <util/Win/GUI/RadioButton.h>
#include <memory>

namespace WIN32TEST {
namespace Notepad {
namespace GUI {

class PageSetupWindow : public Util::Win::GUI::Window
{
public:
    PageSetupWindow(HWND hwnd);
    ~PageSetupWindow();

public:  // interface
    void setPortrait();
    void setLandscape();

private: // internal structs
    enum CtrlsId
    {
        PortraitRb  = 1056,
        LandscapeRb = 1057
    };

private: // internal typedefs
    typedef Util::Win::GUI::RadioButton RadioButton;

private: // member variables
    RadioButton _portrait;
    RadioButton _landscape;
};

typedef std::shared_ptr<PageSetupWindow> PageSetupWindowPtr;

} // namespace GUI
} // namespace Notepad
} // namespace WIN32TEST
