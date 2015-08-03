#include "stdafx.h"
#include "Application.h"

using namespace WIN32TEST;

Application::Application()
{
}

Application::~Application()
{
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