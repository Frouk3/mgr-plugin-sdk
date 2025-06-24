#pragma once

#include <hkpCdPointCollector.h>
#include <hkArray.h>
#include <hkpRootCdPoint.h>
#include <shared.h>

class hkpAllCdPointCollector : public hkpCdPointCollector
{
public:
    int field_8;
    int field_C;
    hkInplaceArray<hkpRootCdPoint, 8> m_points;

    void sortHits()
    {
        ((void(__thiscall*)(hkpAllCdPointCollector*))(shared::base + 0xD2BCF0))(this);
    }

    hkpAllCdPointCollector()
    {
        ((void(__thiscall *)(hkpAllCdPointCollector*))(shared::base + 0x38860))(this);
    }

    ~hkpAllCdPointCollector()
    {
        ((void(__thiscall *)(hkpAllCdPointCollector*))(shared::base + 0x388C0))(this);
    }
};

VALIDATE_SIZE(hkpAllCdPointCollector, 0x1A0);