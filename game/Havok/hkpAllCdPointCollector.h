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

    hkpAllCdPointCollector()
    {
        MAKE_CALL(shared::base + 0x38860, void(__thiscall *)(hkpAllCdPointCollector *), this);
    }

    void sortHits()
    {
        MAKE_CALL(shared::base + 0xD2BCF0, void(__thiscall *)(hkpAllCdPointCollector *), this);
    }
};

VALIDATE_SIZE(hkpAllCdPointCollector, 0x1A0);