#pragma once

#include <Behavior.h>

/// PG: Perhaps we should have base rather than declaring each field for each weapon individually
/// PG: HELL YEAH! *leaves this class untouched*

class Wp030a : public Behavior
{
public:
    int field_870;
    int field_874;
    int field_878;
    int field_87C;
    int field_880;
    int field_884;
    int field_888;
    int field_88C;
    int field_890;
    int field_894;
    int field_898;
    int field_89C;
    int field_8A0;
    int field_8A4;
    int field_8A8;
    int field_8AC;
    int field_8B0;
    int field_8B4;
    int field_8B8;
    int field_8BC;
    int field_8C0;
    int field_8C4;
    int field_8C8;
    int field_8CC;

    Wp030a()
    {
        ((void(__thiscall *)(Wp030a *))(shared::base + 0x6A6750))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735450);
};

VALIDATE_SIZE(Wp030a, 0x8D0);