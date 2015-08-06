#include "MainWindow.h"
#include "SaveAsWindow.h"
#include <ppltasks.h>

using namespace WIN32TEST::Notepad::GUI;
using namespace Util::Win::GUI;

using namespace concurrency;

namespace { const size_t timeout = 60000; }

MainWindow::MainWindow(HWND hwnd, HANDLE process)
    : Window(hwnd)
    , _process{ process }
    , _document(get<Edit>(Document))
{
}

MainWindow::~MainWindow()
{
}

// interface

void MainWindow::saveAs(const std::string &/*path*/, OnSaved onSaved)
{
    PostMessage(WM_COMMAND, MAKEWPARAM(SaveAs, 0), 0);

    create_task([=]() // go async
    {
        const std::string title{ "Save As" };

        if (SaveAsWindow wnd = Window::waitFor(Window::dialogClass(), title, timeout))
        {
            onSaved(true, "");
        }
        else
        {
            onSaved(false, "Could not find '" + title + "' window");
        }
    });
}


void MainWindow::write(const std::string &text)
{
    _document.setText(text);
}


std::string MainWindow::read()
{
    return _document.getText();
}

void MainWindow::exit()
{
    PostMessage(WM_COMMAND, MAKEWPARAM(Exit, 0), 0);

    ::WaitForSingleObject(_process, INFINITE);
}