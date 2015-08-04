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

Application::Process Application::launch(SHELLEXECUTEINFO *param)
{
    if (!::ShellExecuteEx(param))
    {
        throw std::exception("Failed to luanch application");
    }

    return param->hProcess;
}