#include "ReplaceWindow.h"

using namespace WIN32TEST::Notepad::GUI;
using namespace Util::Win::GUI;

ReplaceWindow::ReplaceWindow(HWND hwnd)
    : Window(hwnd),
    _findWhat(get<Edit>(FindWhatTxt)),
    _replaceWith(get<Edit>(ReplaceWithTxt)),
    _replaceAll(get<Button>(ReplaceAllBtn))
{
}

ReplaceWindow::~ReplaceWindow()
{
}

// interface

void ReplaceWindow::setFindWhat(const std::string &value)
{
    _findWhat.setText(value);
}

void ReplaceWindow::setReplaceWith(const std::string &value)
{
    _replaceWith.setText(value);
}

void ReplaceWindow::clickReplaceAll()
{
    _replaceAll.click();
}

void ReplaceWindow::replaceAll(
    const std::string &what,
    const std::string &with)
{
    setFindWhat(what);
    setReplaceWith(with);
    clickReplaceAll();

    clickCancel();
}
