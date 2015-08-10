#include "stdafx.h"
#include "Window.h"
#include "Text.h"

using namespace Util;
using namespace Util::Win::GUI;

namespace { const size_t timeout = 20000; }

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

    waitUntil(timeout, [&]()
    {
        ::EnumWindows(&enumWindowsProc, reinterpret_cast<LPARAM>(&wnd));

        if (wnd.hwnd)
        {
            return true; // Stop
        }

        return false; // Continue looping
    });

    return wnd.hwnd;
}

const std::string & Window::dialogClass()
{
    static const std::string dialogClass{ "#32770" };

    return dialogClass;
}

// interface

Window::operator bool() const
{
    return m_hWnd != nullptr;
}

void Window::clickOk()
{
    clickBtn(IDOK);
}

void Window::clickCancel()
{
    clickBtn(IDCANCEL);
}

// internal class helpers

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

HWND Window::getRecursive(
    HWND parent,
    const wchar_t *className,
    const wchar_t *title)
{
    HWND hwnd = ::FindWindowEx(parent, nullptr, className, title);

    if (hwnd)
    {
        return hwnd;
    }

    for (HWND h = ::FindWindowEx(parent, nullptr, nullptr, nullptr)
        ; h != nullptr
        ; h = ::GetNextWindow(h, GW_HWNDNEXT))
    {
        hwnd = getRecursive(h, className, title);

        if (hwnd)
        {
            return hwnd;
        }
    }

    return HWND{};
}

void Window::waitUntil(size_t timeout, std::function<bool()> onStep)
{
    for (DWORD stop = ::GetTickCount() + timeout; stop > ::GetTickCount(); ::Sleep(2))
    {
        if (onStep())
        {
            break;
        }
    }
}

// internal helpers

bool Window::waitUntilCreate(int ctrlId, size_t timeout)
{
    bool found = false;

    waitUntil(timeout, [&]()
    {
        if (GetDlgItem(ctrlId))
        {
            found = true;

            return true; // Stop
        }

        return false; // Continue looping
    });

    return found;
}

HWND Window::getById(int ctrlId)
{
    if (!waitUntilCreate(ctrlId, timeout))
    {
        throw std::exception(
            ("Control with id '" + std::to_string(ctrlId) + "' not found").c_str());
    }

    return GetDlgItem(ctrlId);
}

HWND Window::getByText(const std::string &text)
{
    HWND hwnd{};

    waitUntil(timeout, [&]()
    {
        HWND control = getRecursive(
            *this,
            nullptr,
            Text::Convert::wcsFromUtf(text).c_str());

        if (control)
        {
            hwnd = control;

            return true; // Stop
        }

        return false; // Continue looping
    });

    return hwnd;
}

// protected helpers

void Window::clickBtn(int id)
{
    if (CWindow btn = GetDlgItem(id))
    {
        PostMessage(
            WM_COMMAND,
            MAKEWPARAM(id, BN_CLICKED),
            reinterpret_cast<LPARAM>(btn.m_hWnd));
    }
}
