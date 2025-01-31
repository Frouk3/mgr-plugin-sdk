#pragma once

#include <Behavior.h>

class Et0060 : public Behavior
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

    Et0060()
    {
        ((void(__thiscall *)(Et0060 *))(shared::base + 0x6A6A20))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x17352AC);
};

VALIDATE_SIZE(Et0060, 0x8B0);