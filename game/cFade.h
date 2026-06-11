#pragma once

#include <Hw.h>
#include <cOtManager.h>

enum eFadeId : int
{
    eFadePauseSimple = -4,
    eFadePause = -3,
    eFadeRoomJump = -2,
    eFadeEvent = -1,
    eFadeScenario = -1,
    eFadeInvalid = 0,
    eFadeNew = 0,
};


class cFade
{
public:
    enum { WORK_NUM = 4 };
    class cWork
    {
    public:
        enum FLAG
        {
            FLAG_UNDYING = 1,
            FLAG_SET_RATE = 2
        };

        eFadeId m_FadeId;
        int m_Prio;
        unsigned int m_Flag;
        unsigned int m_ColStart;
        unsigned int m_ColEnd;
        int m_TimeCount;
        int m_TimeLength;
        float m_Rate;
        OT_TYPE m_OtType;
        int m_OtDepth;
    };

    Hw::cFactoryFixed<cWork, 4> m_WorkFactory;
    Hw::cFixedList<cWork*> m_WorkPtrList;
    eFadeId m_RotateId;

    int startup(Hw::cHeap& rHeap, int work_num) { return MAKE_CALL(shared::base + 0xABBF70, int(__thiscall *)(cFade *, Hw::cHeap &, int), this, rHeap, work_num); }
    void update() { MAKE_CALL(shared::base + 0xABDDC0, void(__thiscall *)(cFade *), this); }
    void trans() { MAKE_CALL(shared::base + 0xAB4040, void(__thiscall *)(cFade *), this); }
    void cleanup() { MAKE_CALL(shared::base + 0xAC1A50, void(__thiscall *)(cFade *), this); }
    eFadeId set(eFadeId id, unsigned int col_start, unsigned int col_end, int time, unsigned int flags, int prio, OT_TYPE ot_type) { return MAKE_CALL(shared::base + 0xAC1AB0, eFadeId(__thiscall *)(cFade *, eFadeId, unsigned int, unsigned int, int, unsigned int, int, OT_TYPE), this, id, col_start, col_end, time, flags, prio, ot_type); }
    void setRate(eFadeId id, float rate) { MAKE_CALL(shared::base + 0xAB42D0, void(__thiscall *)(cFade *, eFadeId, float), this, id, rate); }
    void kill(eFadeId id) { MAKE_CALL(shared::base + 0xABDD50, void(__thiscall *)(cFade *, eFadeId), this, id); }
    void killAll() { MAKE_CALL(shared::base + 0xABDDD0, void(__thiscall *)(cFade *), this); }
    int isEnd(eFadeId id) { return MAKE_CALL(shared::base + 0xAB4340, int(__thiscall *)(cFade *, eFadeId), this, id); }
    int isAlive(eFadeId id) { return MAKE_CALL(shared::base + 0xAB4300, int(__thiscall *)(cFade *, eFadeId), this, id); }

    cWork *newWork(eFadeId id, int prio) { MAKE_CALL(shared::base + 0xABDE50, void(__thiscall *)(cFade *, eFadeId, int), this, id, prio); }

    cFade() { MAKE_CALL(shared::base + 0xAC41C0, void(__thiscall *)(cFade *), this); }
    ~cFade() { MAKE_CALL(shared::base + 0xAC41F0, void(__thiscall *)(cFade *), this); }
};

inline cFade& g_Fade = *(cFade*)(shared::base + 0x1ADC6C0);