#pragma once

#include <atlbase.h>
#include <atlwin.h>
#include <functional>
#include <memory>

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
    void clickOk();
    void clickCancel();

public:  // class interface
    static HWND waitFor(
        const std::string &className,
        const std::string &title,
        size_t timeout);
    static const std::string & dialogClass();
    template <class Dialog>
    static void handleDialog(
        const std::string &title,
        std::function<void(std::shared_ptr<Dialog>)> onDialog)
    {
        if (Dialog d = waitFor(dialogClass(), title, timeout))
        {
            onDialog(std::make_shared<Dialog>(d));
        }
        else
        {
            onDialog(std::shared_ptr<Dialog>{});
        }
    };

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
    static void waitUntil(size_t timeout, std::function<bool()> onStep);

private: // internal helpers
    bool waitUntilCreate(int ctrlId, size_t timeout);
    HWND getById(int ctrlId);
    HWND getByText(const std::string &text);

protected: // protected helpers
    void clickBtn(int id);
};

} // GUI namespace
} // Win namespace
} // Util namespace
