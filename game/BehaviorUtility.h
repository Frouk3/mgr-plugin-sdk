#pragma once

#include <hkpAllCdPointCollector.h>
#include <hkpAllRayHitCollector.h>
#include <Entity.h>
#include "Hw.h"

namespace BehaviorUtility
{
    struct RayCast
    {
        int field_0;
        int field_4;
        int field_8;
        int field_C;
        cVec4 m_vecOut;
        cVec4 m_vecOutDirection;
        Entity* m_pEntity;
        int field_34;
        int field_38;
        int field_3C;
        hkpAllRayHitCollector m_RayHitCollector;
        hkpAllCdPointCollector m_CdPointCollector;
        cVec4 m_vecOrigin;
        cVec4 m_vecEndRayPoint;

        RayCast()
        {
            ((void(__thiscall*)(RayCast*))(shared::base + 0x689310))(this);
        }

        ~RayCast()
        {
            ((void(__thiscall*)(RayCast*))(shared::base + 0x689390))(this);
        }

        void drawRayInfo(unsigned int color, unsigned int debugLayer, const char* text)
        {
            ((void(__thiscall*)(RayCast*, unsigned int, unsigned int, const char*))(shared::base + 0x684420))(this, color, debugLayer, text);
        }
    };

    struct RayInfo
    {
        cVec4 m_vecOrigin;
        cVec4 m_vecEndRayPoint;
        int m_nRayId;
        int field_24;
        float m_fRadius;
        int m_bMultiHit;
        int m_bLinearCast;

        void drawRayInfo(unsigned int color, int debugLayer, const char* text)
        {
            ((void(__thiscall*)(RayInfo*, unsigned int, int, const char*))(shared::base + 0x684140))(this, color, debugLayer, text);
        }
    };

    int checkRay(RayCast* rayCast, RayInfo* rayInfo)
    {
        return ((int(__cdecl*)(RayCast*, RayInfo*))(shared::base + 0x686290))(rayCast, rayInfo);
    }
}
