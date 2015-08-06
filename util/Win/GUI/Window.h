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
    template <class Control>
    Control get(int id)
    {
        return Control(getById(id));
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

private: // internal helpers
    bool waitUntil(int ctrlId, size_t timeout);
    HWND getById(int ctrlId);
};

} // GUI namespace
} // Win namespace
} // Util namespace
