#pragma once

enum eSlowRate : int
{
    eRateType_Scene,
    eRateType_Pl,
    eRateType_Em,
    eRateType_Etc,
    eRateType_Max
};

class cSlowRateUnit
{
public:
    void* m_pAllocList; // maybe unused
    eSlowRate m_SlowRateType;
    int m_RefCount;
    float m_SlowRate;
    float m_Rate;
    float m_RateBefore;
    float m_Delta;
    int m_IsActive;
    int m_FadeOutTicks;
    int m_InitialFadeOut;

    cSlowRateUnit() { MAKE_CALL(shared::base + 0xA03B60, void(__thiscall *)(cSlowRateUnit*), this); }
    void move() { MAKE_CALL(shared::base + 0xA03B90, void(__thiscall *)(cSlowRateUnit*), this); }
    float updateDelta() { return MAKE_CALL(shared::base + 0xA03BD0, float(__thiscall *)(cSlowRateUnit*), this); }
    void setType(eSlowRate type) { MAKE_CALL(shared::base + 0xA03C20, void(__thiscall *)(cSlowRateUnit*, eSlowRate), this, type); }
    eSlowRate getType() { return MAKE_CALL(shared::base + 0xA03C30, eSlowRate(__thiscall *)(cSlowRateUnit*), this); }
    void set(float rate) { MAKE_CALL(shared::base + 0xA03C40, void(__thiscall *)(cSlowRateUnit*, float), this, rate); }
    float get() { return MAKE_CALL(shared::base + 0xA03CB0, float(__thiscall *)(cSlowRateUnit*), this); }
    void setSlowRate(float slowRate) { MAKE_CALL(shared::base + 0xA03CC0, void(__thiscall *)(cSlowRateUnit*, float), this, slowRate); }
    float getSlowRate() { return MAKE_CALL(shared::base + 0xA03CE0, float(__thiscall *)(cSlowRateUnit*), this); }
    int getRefCount() { return MAKE_CALL(shared::base + 0xA03CF0, int(__thiscall *)(cSlowRateUnit*), this); }
};

VALIDATE_SIZE(cSlowRateUnit, 0x28);