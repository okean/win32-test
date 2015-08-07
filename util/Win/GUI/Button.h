#pragma once

#include "Control.hpp"

namespace Util {
namespace Win {
namespace GUI {

class Button : public Util::Win::GUI::Control<WTL::CButton>
{
public:
    Button(HWND hwnd);
    virtual ~Button();

public:  // interface
    void click();
};

} // GUI namespace
} // Win namespace
} // Util namespace
