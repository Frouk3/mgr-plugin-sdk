#pragma once

#include <Behavior.h>

class Et9200 : public Behavior
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

    Et9200()
    {
        ((void(__thiscall *)(Et9200 *))(shared::base + 0x6A6DF0))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x17352E0);
};

VALIDATE_SIZE(Et9200, 0x8C0);