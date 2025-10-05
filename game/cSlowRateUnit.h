#pragma once

enum eSlowRateType : int
{
    SLOWRATE_GLOBAL,
    SLOWRATE_PL,
    SLOWRATE_EM,
    SLOWRATE_ETC
};

class cSlowRateUnit
{
public:
    int field_0;
    eSlowRateType m_nSlowRateType;
    int m_nRefCount;
    float m_fSlowRate;
    float m_fRate;
    float m_fRateBefore;
    float m_fDelta;
    int m_bIsActive;
    int m_nFadeOutTicks;
    int m_nInitialFadeOut;
    cSlowRateUnit *m_pPrev, *m_pNext;
    int field_30;

    cSlowRateUnit()
    {
        ((void(__thiscall *)(cSlowRateUnit*))(shared::base + 0xA03B60))(this);
    }

    void updateDelta()
    {
        ((void(__thiscall *)(cSlowRateUnit*))(shared::base + 0xA03BD0))(this);
    }

    void setSlowRateType(eSlowRateType type)
    {
        ((void(__thiscall *)(cSlowRateUnit*, int))(shared::base + 0xA03C20))(this, type);
    }

    eSlowRateType getSlowRateType()
    {
        return ((eSlowRateType(__thiscall *)(cSlowRateUnit*))(shared::base + 0xA03C30))(this);
    }

    float getDelta()
    {
        return ((float(__thiscall *)(cSlowRateUnit*))(shared::base + 0xA03CB0))(this);
    }

    void setSlowRate(float slowRate)
    {
        ((void(__thiscall *)(cSlowRateUnit*, float))(shared::base + 0xA03CC0))(this, slowRate);
    }

    float getSlowRate()
    {
        return ((float(__thiscall *)(cSlowRateUnit*))(shared::base + 0xA03CE0))(this);
    }

    int getRefCount()
    {
        return ((int(__thiscall *)(cSlowRateUnit*))(shared::base + 0xA03CF0))(this);
    }
};

VALIDATE_SIZE(cSlowRateUnit, 0x34);