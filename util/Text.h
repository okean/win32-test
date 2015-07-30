#pragma once

#include <string>

namespace Util {

class Text
{

public: // public classes

    struct Convert
    {
        static std::wstring     wcsFromUtf(const std::string &str);
        static std::string      utfFromWcs(const std::wstring &str);
    };
};

} // Util namespace