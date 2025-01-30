#pragma once

#include <Hw.h>

class cFade
{
public:
    struct Unit
    {
        int field_0;
        int m_nPriority;
        int m_nFadeFlags;
        int m_nStartFade;
        int m_nEndFade;
        int m_nFadeTicks;
        int field_18;
        int field_1C;
        int field_20;
        int field_24;
    };
    
    int field_0;
    int field_4;
    Hw::cHeapFixed m_UnitFactory;
    Hw::cFixedList<Unit*> m_UnitList;
    int field_84;
};