#include "CheckBox.h"

using namespace Util::Win::GUI;

CheckBox::CheckBox(HWND hwnd) : Control<WTL::CButton>(hwnd)
{
}

CheckBox::~CheckBox()
{
}

// interface

void CheckBox::tick()
{
    SetCheck(BST_CHECKED);
}

void CheckBox::untick()
{
    SetCheck(BST_UNCHECKED);
}

bool CheckBox::isTicked()
{
    const int state = GetCheck();
    
    switch (state)
    {
    case BST_CHECKED:
    case BST_INDETERMINATE:
        return true;
    case BST_UNCHECKED:
        return false;
    }

    throw std::exception(
        ("Invalid CheckBox state " + std::to_string(state)).c_str());
}
