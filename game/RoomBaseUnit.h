#pragma once

#include <Behavior.h>

class RoomBaseUnit : public Behavior
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

    RoomBaseUnit()
    {
        ((void(__thiscall *)(RoomBaseUnit*))(shared::base + 0x6A6F70))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x173534C);
};

VALIDATE_SIZE(RoomBaseUnit, 0x890);