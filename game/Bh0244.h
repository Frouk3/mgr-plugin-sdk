#pragma once

#include <BehaviorBh.h>

class Bh0244 : public BehaviorBh
{
public:
    int field_C10;
    int field_C14;
    int field_C18;
    int field_C1C;

    Bh0244()
    {
        MAKE_CALL(shared::base + 0x10470, void(__thiscall *)(Bh0244 *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1734B74);
};

VALIDATE_SIZE(Bh0244, 0xC20);