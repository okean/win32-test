#pragma once

#include <util/Win/GUI/Window.h>
#include <util/Win/GUI/Button.h>
#include <util/Win/GUI/Edit.h>
#include <memory>

namespace WIN32TEST {
namespace Notepad {
namespace GUI {

class ReplaceWindow : public Util::Win::GUI::Window
{
public:
    ReplaceWindow(HWND hwnd);
    ~ReplaceWindow();

public:  // interface
    void setFindWhat(const std::string &value);
    void setReplaceWith(const std::string &value);
    void clickReplaceAll();
    void replaceAll(
        const std::string &what,
        const std::string &with);

private: // internal structs
    enum CtrlsId
    {
        FindWhatTxt     = 1152,
        ReplaceWithTxt  = 1153,
        MatchCaseBtn    = 1041,
        ReplaceAllBtn   = 1025
    };

private: // internal typedefs
    typedef Util::Win::GUI::Edit    Edit;
    typedef Util::Win::GUI::Button  Button;

private: // internal helpers

private: // member variables
    Edit    _findWhat;
    Edit    _replaceWith;
    Button  _replaceAll;
};

typedef std::shared_ptr<ReplaceWindow> ReplaceWindowPtr;

} // namespace GUI
} // namespace Notepad
} // namespace WIN32TEST
