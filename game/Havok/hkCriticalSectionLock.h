#pragma once

#include <Windows.h>

struct hkCriticalSectionLock
{
    CRITICAL_SECTION m_section;
};