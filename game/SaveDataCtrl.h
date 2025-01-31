#pragma once

#include <Hw.h>

namespace SaveDataCtrl
{
    struct SlotInfo
    {
        int field_0;
        int field_4;
        int field_8;
        int field_C;
    };

    struct GraphicSettings
    {
    public:
        int m_nResolution;
        int m_nTextureFiltering;
        int m_nBlurDisabled;
        int m_nShadow;
        int m_nBrightness;
        int pad14;
        int m_nWindowed;
        int m_nAntialiasing;
        int m_nZangeki;
        int m_nZantime;
    };
}

class ProgressFlagBase
{
public:
    int field_4;
    int field_8;
    int field_C;
    Hw::CriticalSection m_CriticalSection;
    int field_2C;

    virtual ~ProgressFlagBase() {};
};

class ProgressFlag : public ProgressFlagBase{};

class ProgressFlagBase_Dlc
{
public:
    int field_4;
    int field_8;
    int field_C;
    Hw::CriticalSection m_CriticalSection;
    int field_2C;

    virtual ~ProgressFlagBase_Dlc() {};
};

class ProgressFlagDlc2 : public ProgressFlagBase_Dlc{};

class ProgressFlagDlc3 : public ProgressFlagBase_Dlc{};