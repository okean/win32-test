#pragma once

#include "Control.hpp"

namespace Util {
namespace Win {
namespace GUI {

class CheckBox : public Util::Win::GUI::Control<WTL::CButton>
{
public:
    CheckBox(HWND hwnd);
    virtual ~CheckBox();

public:  // interface
    void tick();
    void untick();
    bool isTicked();
};

} // GUI namespace
} // Win namespace
} // Util namespace
