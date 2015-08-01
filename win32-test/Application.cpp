#include "stdafx.h"
#include "Application.h"
#include <Windows.h>
#include <ppltasks.h>

using namespace WIN32TEST;

using namespace concurrency;

Application::Application()
{
}

Application::~Application()
{
}

// class helpers

void Application::launchApp()
{
    Process process = launch();
}

// internal static helpers

Application::Process Application::launch()
{
    SHELLEXECUTEINFO shellInfo = { sizeof(shellInfo) };

    shellInfo.lpVerb        = L"open";
    shellInfo.lpFile        = L"notepad.exe";
    shellInfo.lpParameters  = 0;
    shellInfo.nShow         = SW_NORMAL;
    shellInfo.fMask         = SEE_MASK_NOCLOSEPROCESS;

    if (!::ShellExecuteEx(&shellInfo))
    {
        throw std::exception("Failed to luanch application");
    }

    return shellInfo.hProcess;
}