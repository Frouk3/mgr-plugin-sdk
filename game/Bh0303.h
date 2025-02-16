#pragma once

#include <BehaviorBh.h>

class Bh0303 : public BehaviorBh
{
public:
    int field_C10;
    int field_C14;
    int field_C18;
    int field_C1C;

    Bh0303()
    {
        ((void(__thiscall *)(Bh0303 *))(shared::base + 0x6B16E0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17354E4);
};

VALIDATE_SIZE(Bh0303, 0xC20);