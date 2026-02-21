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

    cSlowRateUnit() { CallMethod<0xA03B60, cSlowRateUnit *>(this); }
    void move() { CallMethod<0xA03B90, cSlowRateUnit *>(this); }
    float updateDelta() { return ReturnCallMethod<float, 0xA03BD0, cSlowRateUnit *>(this);}
    void setType(eSlowRate type) { CallMethod<0xA03C20, cSlowRateUnit *>(this, type); }
    eSlowRate getType() { return ReturnCallMethod<eSlowRate, 0xA03C30, cSlowRateUnit *>(this); }
    void set(float rate) { CallMethod<0xA03C40, cSlowRateUnit *>(this, rate); }
    float get() { return ReturnCallMethod<float, 0xA03CB0, cSlowRateUnit *>(this); }
    void setSlowRate(float slowRate) { CallMethod<0xA03CC0, cSlowRateUnit *>(this, slowRate); }
    float getSlowRate() { return ReturnCallMethod<float, 0xA03CE0, cSlowRateUnit *>(this); }
    int getRefCount() { return ReturnCallMethod<int, 0xA03CF0, cSlowRateUnit *>(this); }
};

VALIDATE_SIZE(cSlowRateUnit, 0x28);