#pragma once

#include "Control.hpp"

namespace Util {
namespace Win {
namespace GUI {

class RadioButton : public Util::Win::GUI::Control<WTL::CButton>
{
public:
    RadioButton(HWND hwnd);
    virtual ~RadioButton();

public:  // interface
    void select();
    bool isSelected();
};

} // GUI namespace
} // Win namespace
} // Util namespace
