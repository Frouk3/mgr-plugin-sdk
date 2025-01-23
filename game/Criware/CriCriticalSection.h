#pragma once

#include <shared.h>

struct CriCriticalSection
{
    CRITICAL_SECTION m_CritSection;
    int m_CurrentThreadId;
    int m_RefNum;
};