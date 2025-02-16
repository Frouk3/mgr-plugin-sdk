#pragma once

#include <Behavior.h>

class Et000d : public Behavior
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

    Et000d()
    {
        ((void(__thiscall *)(Et000d *))(shared::base + 0x6A6990))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x17352A0);
};

VALIDATE_SIZE(Et000d, 0x8A0);