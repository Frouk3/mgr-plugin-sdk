#pragma once

#include <Behavior.h>

class cItemObjectBase : public Behavior
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
    float field_890;
    float field_894;
    float field_898;
    float field_89C;
    int field_8A0;
    int field_8A4;
    int field_8A8;
    int field_8AC;
    int field_8B0;
    int field_8B4;
    int field_8B8;
    int field_8BC;
    float field_8C0;
    float field_8C4;
    float field_8C8;
    float field_8CC;
    float field_8D0;
    float field_8D4;
    int field_8D8;
    int field_8DC;
    Hw::CriticalSection field_8E0;
    int field_8FC;
    int field_900;
    int field_904;
    int field_908;
    int field_90C;
    int field_910;
    int field_914;
    int field_918;
    float field_91C;

    cItemObjectBase()
    {
        ((void(__thiscall *)(cItemObjectBase*))(shared::base + 0x6A7300))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x1735390);
};

VALIDATE_SIZE(cItemObjectBase, 0x920);