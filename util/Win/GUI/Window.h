#pragma once

#include <atlbase.h>
#include <atlwin.h>
#include <functional>

namespace Util {
namespace Win {
namespace GUI {

class Window : public ATL::CWindow
{
public:
    Window(HWND hwnd);
    virtual ~Window();

public:  // exposing some wtl attributes
    using ATL::CWindow::operator HWND; 

public:  //interface
    operator bool() const;
    template <class Control>
    Control get(int id)
    {
        return Control(getById(id));
    };
    template <class Control>
    Control get(const std::string &text)
    {
        return Control(getByText(text));
    };

public:  // class interface
    static HWND waitFor(
        const std::string &className,
        const std::string &title,
        size_t timeout);
    static const std::string & dialogClass();

private: // internal structs
    struct WindowInfo
	{
        std::wstring className;
        std::wstring title;
        HWND hwnd;
    };

private: // internal class helpers
    static BOOL CALLBACK enumWindowsProc(HWND hwnd, LPARAM lparam);
    static HWND getRecursive(
        HWND parent, 
        const wchar_t *className, 
        const wchar_t *title);

private: // internal helpers
    bool waitUntil(int ctrlId, size_t timeout);
    HWND getById(int ctrlId);
    HWND getByText(const std::string &text);
};

} // GUI namespace
} // Win namespace
} // Util namespace
