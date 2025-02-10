#pragma once

#include <BehaviorBm.h>

class ArmoredCarObj : public BehaviorBm
{
public:
    int field_B40;
    int field_B44;
    int field_B48;
    int field_B4C;

    ArmoredCarObj()
    {
        ((void(__thiscall *)(ArmoredCarObj*))(shared::base + 0x6B0BB0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734C10);
};

VALIDATE_SIZE(ArmoredCarObj, 0xB50);