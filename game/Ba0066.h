#pragma once

#include <BehaviorBa.h>

class Ba0066 : public BehaviorBa
{
public:
    int field_B30;
    int field_B34;
    int field_B38;
    int field_B3C;

    Ba0066()
    {
        MAKE_CALL(shared::base + 0x6B0200, void(__thiscall *)(Ba0066*), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1734B1C);
};

VALIDATE_SIZE(Ba0066, 0xB40);