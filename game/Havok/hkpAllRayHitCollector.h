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

    hkInplaceArray<hkpWorldRayCastOutput, 8> m_output;

    hkpAllRayHitCollector()
    {
        ((void(__thiscall *)(hkpAllRayHitCollector *))(shared::base + 0x1EC620))(this);
    }
};