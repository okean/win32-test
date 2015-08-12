#include "ReplaceWindow.h"

using namespace WIN32TEST::Notepad::GUI;
using namespace Util::Win::GUI;

ReplaceWindow::ReplaceWindow(HWND hwnd)
    : Window(hwnd),
    _findWhat(get<Edit>(FindWhatTxt)),
    _replaceWith(get<Edit>(ReplaceWithTxt)),
    _replaceAll(get<Button>(ReplaceAllBtn)),
    _matchCase(get<CheckBox>(MatchCaseBtn))
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

void ReplaceWindow::tickMatchCase()
{
    if (!_matchCase.isTicked())
    {
        _matchCase.tick();
    }
}

void ReplaceWindow::clickReplaceAll()
{
    _replaceAll.click();
}

void ReplaceWindow::replaceAll(
    const std::string &what,
    const std::string &with,
    bool matchCase)
{
    setFindWhat(what);
    setReplaceWith(with);
    
    if (matchCase)
    {
        tickMatchCase();
    }
    
    clickReplaceAll();
    clickCancel();
}
