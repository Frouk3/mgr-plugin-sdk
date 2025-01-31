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
    eSlowRateType m_nSlowRateType;
    int m_nReferences;
    float m_fSlowRate;
    float m_fRate;
    float m_fRateBefore;
    float m_fDelta;
    int field_1C;
    int field_20;
    int field_24;
    cSlowRateUnit *field_28;
    cSlowRateUnit *field_2C;
    int field_30;

    virtual ~cSlowRateUnit() {};
};