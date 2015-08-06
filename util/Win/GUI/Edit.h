#pragma once

#include "Control.hpp"

namespace Util {
namespace Win {
namespace GUI {

class Edit : public Util::Win::GUI::Control<WTL::CEdit>
{
public:
    Edit(HWND hwnd);
    virtual ~Edit();

public:  // interface
    void setText(const std::string &value);
    std::string getText();
};

} // GUI namespace
} // Win namespace
} // Util namespace
