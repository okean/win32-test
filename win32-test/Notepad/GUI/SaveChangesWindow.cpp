#include "SaveChangesWindow.h"

using namespace WIN32TEST::Notepad::GUI;
using namespace Util::Win::GUI;

SaveChangesWindow::SaveChangesWindow(HWND hwnd)
    : Window(hwnd),
    _dontSaveBtn(get<Button>("Do&n't Save"))
{
}

SaveChangesWindow::~SaveChangesWindow()
{
}

// interface

void SaveChangesWindow::dontSave()
{
    _dontSaveBtn.click();
}