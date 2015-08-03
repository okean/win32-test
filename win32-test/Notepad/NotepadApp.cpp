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
    launchApp<MainWindow>(onLaunched);
}