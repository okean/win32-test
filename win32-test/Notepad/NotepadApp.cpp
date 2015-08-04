#include "stdafx.h"
#include "NotepadApp.h"
#include "Application.h"
#include "GUI/MainWindow.h"

using namespace WIN32TEST::Notepad;
using namespace WIN32TEST::Notepad::GUI;

NotepadApp::NotepadApp()
{
}

NotepadApp::~NotepadApp()
{
}

// class helpers

void NotepadApp::launch(OnLaunched onLaunched)
{
    launchApp<MainWindow>(className(), title(), &param(), onLaunched);
}

// internal static helpers

SHELLEXECUTEINFO & NotepadApp::param()
{
    static SHELLEXECUTEINFO param = { sizeof(param) };

    param.lpVerb = L"open";
    param.lpFile = L"notepad.exe";
    param.lpParameters = 0;
    param.nShow = SW_NORMAL;
    param.fMask = SEE_MASK_NOCLOSEPROCESS;

    return param;
}

const std::string & NotepadApp::className()
{
    static const std::string className{ "Notepad" };

    return className;
}

const std::string & NotepadApp::title()
{
    static const std::string title{ "Untitled - Notepad" };

    return title;
}