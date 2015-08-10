#include "SaveChangesWindow.h"

using namespace WIN32TEST::Notepad::GUI;
using namespace Util::Win::GUI;

SaveChangesWindow::SaveChangesWindow(HWND hwnd)
    : Window(hwnd),
    _dontSaveBtn(get<Button>(ctrlIdToString(dontSaveTxt)))
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

// internal helpers

const std::string SaveChangesWindow::ctrlIdToString(CtrlsId id)
{
    switch (id)
    {
    case CtrlsId::dontSaveTxt:
        return "Do&n't Save";
    }

    throw std::exception("Invalid control id");
}