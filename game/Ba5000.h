#pragma once

#include <BehaviorBa.h>

class Ba5000 : public BehaviorBa
{
public:
    int field_B30;
    int field_B34;
    int field_B38;
    int field_B3C;
    int field_B40;
    int field_B44;
    int field_B48;
    int field_B4C;
    int field_B50;
    int field_B54;
    int field_B58;
    int field_B5C;
    int field_B60;
    int field_B64;
    int field_B68;
    int field_B6C;
    int field_B70;
    int field_B74;
    int field_B78;
    int field_B7C;
    int field_B80;
    int field_B84;
    int field_B88;
    int field_B8C;
    int field_B90;
    int field_B94;
    int field_B98;
    int field_B9C;
    int field_BA0;
    int field_BA4;
    int field_BA8;
    int field_BAC;

    Ba5000()
    {
        ((void(__thiscall *)(Ba5000*))(shared::base + 0x6B0D40))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734B38);
};

VALIDATE_SIZE(Ba5000, 0xBB0);