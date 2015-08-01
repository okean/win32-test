#include "stdafx.h"
#include "Text.h"
#include <Windows.h>
#include <cassert>

using namespace Util;

// struct Convert

std::wstring Text::Convert::wcsFromUtf(const std::string &str)
{
    if (str.empty())
    {
        return std::wstring{};
    }

    int size = ::MultiByteToWideChar(
        CP_UTF8, 0,
        &str[0], str.size(),
        nullptr, 0);

    assert(size);

    std::wstring out(size, 0);

    if (size)
    {
        size = ::MultiByteToWideChar(
            CP_UTF8, 0,
            &str[0], str.size(),
            &out[0], out.size());

        assert(size);
    }

    return std::move(out);
}

std::string Text::Convert::utfFromWcs(const std::wstring &str)
{
    if (str.empty())
    {
        return std::string{};
    }

    int size = ::WideCharToMultiByte(
        CP_UTF8, 0,
        &str[0], str.size(),
        nullptr, 0,
        nullptr, nullptr);

    assert(size);

    std::string out(size, 0);

    if (size)
    {
        size = ::WideCharToMultiByte(
            CP_UTF8, 0,
            &str[0], str.size(),
            &out[0], out.size(),
            nullptr, nullptr);

        assert(size);
    }

    return std::move(out);
}