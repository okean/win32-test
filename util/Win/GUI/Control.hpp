#pragma once

#include <stdafx.h>
#include <atlbase.h>
#include <atlwin.h>
#include <WTL/Include/atlapp.h>
#include <WTL/Include/atlctrls.h>

namespace Util {
namespace Win {
namespace GUI {

template <class AtlControl>
class Control : protected AtlControl
{
public:
    Control(HWND hwnd) : AtlControl(hwnd) {}
    virtual ~Control() {}

public:  // exposing some wtl attributes
    using AtlControl::operator HWND;
};

} // GUI namespace
} // Win namespace
} // Util namespace
