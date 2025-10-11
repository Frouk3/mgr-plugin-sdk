#pragma once
#include <Hw.h>

namespace Fw
{
    namespace String
    {
        template <size_t N>
        inline void format(char(&buffer)[N], const char* fmt, ...)
        {
            va_list args;
            va_start(args, fmt);
            vsprintf_s(buffer, fmt, args);
            va_end(args);
        }

        template <size_t N>
        inline void append(char(&buffer)[N], const char *str)
        {
            strcat_s(buffer, N, str);
        }

        template <size_t N>
        inline void copy(char(&buffer)[N], const char *str, rsize_t maxCount)
        {
            strncpy_s(buffer, N, str, maxCount)
        }
    }
}