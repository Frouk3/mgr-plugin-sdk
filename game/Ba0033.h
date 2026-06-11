#pragma once

#include <BehaviorBa.h>

class Ba0033 : public BehaviorBa
{
public:
    int field_B30;
    int field_B34;
    int field_B38;
    int field_B3C;

    Ba0033()
    {
        MAKE_CALL(shared::base + 0x6B0EF0, void(__thiscall *)(Ba0033*), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1734B14);
};

VALIDATE_SIZE(Ba0033, 0xB40);