#pragma once

#include <util/Win/GUI/Window.h>
#include <functional>
#include <memory>
#include <ppltasks.h>

namespace WIN32TEST {

class Application
{
public:
    Application();
    ~Application();

public:  // public typdefs
    template<class T>
    using WindowPtr     = std::shared_ptr<T>;
    template<class T>
    using OnLaunched    = std::function<void(WindowPtr<T>, const std::string &)>;

private: // internal typedef
    typedef Util::Win::GUI::Window  Window;
    typedef void                    *Process;

public: // class helpers
    template<class T>
    static void launchApp(
        const std::string &className,
        const std::string &title,
        SHELLEXECUTEINFO *param, 
        OnLaunched<T> onLaunched)
    {
        concurrency::create_task([=]
        {
            Process process = launch(param);

            if (HWND wnd = Window::waitFor(className, title, 20000))
            {
                onLaunched(std::make_shared<T>(wnd, process), "");
            }
            else
            {
                onLaunched(WindowPtr<T>{}, "Failed to start application");
            }
        });
    }

private: // internal static helpers
    static Process launch(SHELLEXECUTEINFO *param);
};

} // namespace WIN32TEST