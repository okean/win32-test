#include "stdafx.h"
#include "Window.h"
#include "Text.h"

using namespace Util;
using namespace Util::Win::GUI;

Window::Window(HWND hwnd) : ATL::CWindow(hwnd)
{
}

Window::~Window()
{
}

// class interface

HWND Window::waitFor(
    const std::string &className,
    const std::string &title,
    size_t timeout)
{
    WindowInfo wnd{};

    wnd.className	= Text::Convert::wcsFromUtf(className);
    wnd.title		= Text::Convert::wcsFromUtf(title);

    for (DWORD stop = ::GetTickCount() + timeout; stop > ::GetTickCount(); ::Sleep(2))
    {
        ::EnumWindows(&enumWindowsProc, reinterpret_cast<LPARAM>(&wnd));

        if (wnd.hwnd)
        {
            return wnd.hwnd;
        }
    }

    return HWND{};
}

const std::string & Window::dialogClass()
{
    static const std::string dialogClass{ "#32770" };

    return dialogClass;
}

// internal helpers

BOOL CALLBACK Window::enumWindowsProc(HWND hwnd, LPARAM lparam)
{
    WindowInfo *wnd = reinterpret_cast<WindowInfo*>(lparam);

    bool okClass = true;
    bool okTitle = true;

    if (!wnd->className.empty())
    {
        wchar_t className[1024];
        ::GetClassName(hwnd, className, _countof(className));

        okClass = (className == wnd->className);
    }

    if (!wnd->title.empty())
    {
        wchar_t title[1024];
        ::GetWindowText(hwnd, title, _countof(title));

        okTitle = (title == wnd->title);
    }

    if (okClass && okTitle)
    {
        wnd->hwnd = hwnd;

        return FALSE;
    }

    return TRUE;
}
