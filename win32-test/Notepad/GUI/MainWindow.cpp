#include "MainWindow.h"

using namespace WIN32TEST::Notepad::GUI;
using namespace Util::Win::GUI;

MainWindow::MainWindow(HWND hwnd, HANDLE process)
    : Window(hwnd)
    , _process{ process }
{
}

MainWindow::~MainWindow()
{
}