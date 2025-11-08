#pragma once

#include <Hw.h>

class cFade
{
public:
    class cWork
    {
    public:
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

    Hw::cFactoryFixed<cWork, 4> m_UnitFactory;
    Hw::cFixedList<cWork*> m_UnitList;
    int field_84;
};