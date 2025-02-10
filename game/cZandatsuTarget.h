#pragma once

#include <shared.h>
#include <Entity.h>

struct cZandatsuTarget
{
    EntityHandle m_TargetHandle;
    unsigned short m_nTargetBone;
    int m_Flags;
    int field_C;
    float field_10;
    float field_14;
    float field_18;
    int field_1C;
    cVec4 m_vecOffset;
    int field_30;
    int field_34;
    unsigned short field_38;
    unsigned short field_3A;
    float field_3C;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    int field_6C;

    cZandatsuTarget& operator=(const cZandatsuTarget& lhs)
    {
        ((void(__thiscall*)(cZandatsuTarget *, const cZandatsuTarget&))(shared::base + 0x4A50C0))(this, lhs);
        return *this;
    }
};

VALIDATE_SIZE(cZandatsuTarget, 0x70);