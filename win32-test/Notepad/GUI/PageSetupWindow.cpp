#include "PageSetupWindow.h"

using namespace WIN32TEST::Notepad::GUI;
using namespace Util::Win::GUI;

PageSetupWindow::PageSetupWindow(HWND hwnd)
    : Window(hwnd),
    _portrait(get<RadioButton>(PortraitRb)),
    _landscape(get<RadioButton>(LandscapeRb))
{
}

PageSetupWindow::~PageSetupWindow()
{
}

// interface

void PageSetupWindow::setPortrait()
{
    if (!_portrait.isSelected())
    {
        _portrait.select();
    }
}

void PageSetupWindow::setLandscape()
{
    if (!_landscape.isSelected())
    {
        _landscape.select();
    }
}
