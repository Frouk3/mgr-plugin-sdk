#pragma once

#include <BehaviorBa.h>

class Ba041a : public BehaviorBa
{
public:
    int field_B30;
    int field_B34;
    int field_B38;
    int field_B3C;

    Ba041a()
    {
        MAKE_CALL(shared::base + 0x6B0940, void(__thiscall *)(Ba041a*), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1734B30);
};

VALIDATE_SIZE(Ba041a, 0xB40);