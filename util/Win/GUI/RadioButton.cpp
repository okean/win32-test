#include "RadioButton.h"

using namespace Util::Win::GUI;

RadioButton::RadioButton(HWND hwnd) : Control<WTL::CButton>(hwnd)
{
}

RadioButton::~RadioButton()
{
}

// interface

void RadioButton::select()
{
    SetCheck(BST_CHECKED);

    ::PostMessage(
        GetParent(),
        WM_COMMAND,
        MAKEWPARAM(GetDlgCtrlID(), BN_CLICKED),
        reinterpret_cast<LPARAM>(m_hWnd));
}

bool RadioButton::isSelected()
{
    const int state = GetCheck();

    if (state == BST_CHECKED)
    {
        return true;
    }
    else if (state == BST_UNCHECKED)
    {
        return false;
    }
    else
    {
        throw std::exception(
            ("Invalid CheckBox state " + std::to_string(state)).c_str());
    }
}
