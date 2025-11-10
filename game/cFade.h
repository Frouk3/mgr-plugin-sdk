#pragma once

#include <Hw.h>
#include <cOtManager.h>

enum eFadeId
{
    eFadeInvalid
};

class cFade
{
public:
    class cWork
    {
    public:
        eFadeId m_FadeId;
        int m_Prio;
        unsigned int m_Flag;
        unsigned int m_ColStart;
        unsigned int m_ColEnd;
        int m_TimeWait;
        int m_TimeCount;
        int m_TimeLength;
        OT_TYPE m_OtType;
        int field_24;
    };

    Hw::cFactoryFixed<cWork, 4> m_UnitFactory;
    Hw::cFixedList<cWork*> m_UnitList;
    eFadeId m_RotateId;

    void killAll() { ((void(__thiscall *)(cFade *))(shared::base + 0xABDDD0))(this); }
    eFadeId set(eFadeId id, unsigned int col_start, unsigned int col_end, int time, unsigned int flags, int prio, OT_TYPE ot_type) { return ((eFadeId(__thiscall *)(cFade *, eFadeId, unsigned int, unsigned int, int, unsigned int, int, OT_TYPE))(shared::base + 0xAC1AB0))(this, id, col_start, col_end, time, flags, prio, ot_type); }
    cWork *newWork(eFadeId id, int prio) { ((void(__thiscall *)(cFade *, eFadeId, int))(shared::base + 0xABDE50))(this, id, prio); }

    ~cFade() { ((void(__thiscall *)(cFade *))(shared::base + 0xAC41F0))(this); }
};

inline cFade& g_Fade = *(cFade*)(shared::base + 0x1ADC6C0);