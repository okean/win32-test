#include "Edit.h"
#include "Button.h"

using namespace Util;
using namespace Util::Win::GUI;

Button::Button(HWND hwnd) : Control<WTL::CButton>(hwnd)
{
}

Button::~Button()
{
}

// interface

void Button::click()
{
    ::PostMessage(
        GetParent(),
        WM_COMMAND,
        MAKEWPARAM(GetDlgCtrlID(), BN_CLICKED),
        reinterpret_cast<LPARAM>(m_hWnd));
}