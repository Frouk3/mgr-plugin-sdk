#pragma once

#include <BehaviorWeapon.h>

class Em0110CutWhip : public BehaviorWeapon
{
public:
    EntityHandle field_8C0;
    int field_8C4;
    int field_8C8;
    int field_8CC;
    int field_8D0;
    int field_8D4;
    int field_8D8;
    int field_8DC;
    int field_8E0;
    int field_8E4;
    int field_8E8;
    int field_8EC;
    int field_8F0;
    int field_8F4;
    int field_8F8;
    int field_8FC;
    int field_900;
    int field_904;
    int field_908;
    int field_90C;
    int field_910;
    int field_914;
    int field_918;
    int field_91C;
    int field_920;
    int field_924;
    int field_928;
    int field_92C;
    int field_930;
    int field_934;
    int field_938;
    int field_93C;
    int field_940;
    int field_944;
    int field_948;
    int field_94C;
    int field_950;
    int field_954;
    int field_958;
    int field_95C;

    Em0110CutWhip()
    {
        ((void(__thiscall *)(Em0110CutWhip*))(shared::base + 0x6A64F0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734E8C);
};

VALIDATE_SIZE(Em0110CutWhip, 0x960);