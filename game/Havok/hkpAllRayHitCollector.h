#pragma once

#include <hkpRayHitCollector.h>
#include <hkBase.h>
#include <hkArray.h>
#include <hkpWorldRayCastOutput.h>
#include <shared.h>

class hkpAllRayHitCollector : public hkpRayHitCollector
{
public:
    int field_8;
    int field_C;

    hkInplaceArray<hkpWorldRayCastOutput, 8> m_hits;

    hkpAllRayHitCollector()
    {
        MAKE_CALL(shared::base + 0x1EC620, void(__thiscall *)(hkpAllRayHitCollector*), this);
    }

    void sortHits()
    {
        MAKE_CALL(shared::base + 0xD2C170, void(__thiscall *)(hkpAllRayHitCollector*), this);
    }

    inline const hkArray<hkpWorldRayCastOutput>& getHits() const
    {
        return m_hits;
    }
};

VALIDATE_SIZE(hkpAllRayHitCollector, 0x320);