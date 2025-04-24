#pragma once

#include <shared.h>
#include <CriBase.h>

struct CriCriticalSection
{
    CRITICAL_SECTION m_CritSection;
    int m_CurrentThreadId;
    int m_RefNum;
};

inline void CRIAPI CriCriticalSection_enter(CriCriticalSection* section)
{
    ((void(CRIAPI*)(CriCriticalSection*))(shared::base + 0xE941D9))(section);
}

inline void CRIAPI CriCriticalSection_leave(CriCriticalSection *section)
{
    ((void(CRIAPI *)(CriCriticalSection *))(shared::base + 0xE9420C))(section);
}