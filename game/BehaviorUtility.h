#pragma once

#include <hkpAllCdPointCollector.h>
#include <hkpAllRayHitCollector.h>
#include <Entity.h>
#include <Hw.h>
#include <shared.h>

namespace BehaviorUtility
{
    struct RayCast
    {
        int field_0;
        int field_4;
        int field_8;
        int field_C;
        Hw::cVec4 m_TransHit;
        Hw::cVec4 m_HitDir;
        Entity *field_30;
        int field_34;
        int field_38;
        int field_3C;
        hkpAllRayHitCollector m_RayHitCollector;
        hkpAllCdPointCollector m_CdPointCollector;
        Hw::cVec4 m_TransStart;
        Hw::cVec4 m_TransEnd;

        RayCast()
        {
            MAKE_CALL(shared::base + 0x689310, void(__thiscall *)(RayCast *), this);
        }

        ~RayCast()
        {
            MAKE_CALL(shared::base + 0x689390, void(__thiscall *)(RayCast *), this);
        }

        void drawRayInfo(unsigned int color, unsigned int debugLayer, const char* text)
        {
            MAKE_CALL(shared::base + 0x684420, void(__thiscall *)(RayCast *, unsigned int, unsigned int, const char *), this, color, debugLayer, text);
        }
    };

    struct RayInfo
    {
        Hw::cVec4 m_TransStart;
        Hw::cVec4 m_TransEnd;
        int m_CollisionFilter;
        int m_IgnoreObjectFilter;
        float m_Radius;
        BOOL m_bMultiHit;
        BOOL m_bLinearCast;

        void drawRayInfo(unsigned int color, int debugLayer, const char* text)
        {
            MAKE_CALL(shared::base + 0x684140, void(__thiscall *)(RayInfo *, unsigned int, int, const char *), this, color, debugLayer, text);
        }
    };

    int checkRay(RayCast* rayCast, RayInfo* rayInfo)
    {
        return MAKE_CALL(shared::base + 0x686290, int(__cdecl *)(RayCast *, RayInfo *), rayCast, rayInfo);
    }
}

VALIDATE_SIZE(BehaviorUtility::RayCast, 0x520);
VALIDATE_SIZE(BehaviorUtility::RayInfo, 0x34);