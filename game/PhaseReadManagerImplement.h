#pragma once

#include <Hw.h>
#include <PhaseReadManager.h>
#include <shared.h>

class PhaseReadManagerImplement : public PhaseReadManager
{
public:
    int field_4;
    enum ReaderState : int
    {
        None = 0x0,
        StayNoData = 0x1,
        ReadStart = 0x2,
        ReadWait = 0x3,
        StayData = 0x4,
        ReleaseStart = 0x5,
        ReleaseWait = 0x6,
        ReadCancelStart = 0x7,
        ReadCancelWait = 0x8,
    } m_nReaderState;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    Hw::cHeapPhysical field_28;
    int field_498;
    int field_49C;

    static inline PhaseReadManagerImplement *&ms_Instance = *(PhaseReadManagerImplement**)(shared::base + 0x19C51C0);
};

VALIDATE_SIZE(PhaseReadManagerImplement, 0x4A0);