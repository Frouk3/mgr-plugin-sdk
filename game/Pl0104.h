#pragma once

#include <Behavior.h>

class Pl0104 : public Behavior
{
public:
    int field_870;
    int field_874;
    int field_878;
    int field_87C;

    Pl0104()
    {
        ((void(__thiscall *)(Pl0104*))(shared::base + 0x6A6010))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x17353E4);
};

VALIDATE_SIZE(Pl0104, 0x880);