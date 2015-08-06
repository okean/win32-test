#include "Edit.h"
#include "Text.h"

using namespace Util;
using namespace Util::Win::GUI;

Edit::Edit(HWND hwnd) : Control<WTL::CEdit>(hwnd)
{
}

Edit::~Edit()
{
}

// interface

void Edit::setText(const std::string &value)
{
    const std::wstring text { Text::Convert::wcsFromUtf(value) };
    
    SendMessage(WM_SETTEXT, 0, reinterpret_cast<LPARAM>(text.c_str()));
}

std::string Edit::getText()
{
    wchar_t buffer[65536];

    SendMessage(WM_GETTEXT, _countof(buffer), reinterpret_cast<LPARAM>(buffer));

    return Text::Convert::utfFromWcs(buffer);
}