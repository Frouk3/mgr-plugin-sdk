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
        ((void(__thiscall *)(Ba041a*))(shared::base + 0x6B0940))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734B30);
};

VALIDATE_SIZE(Ba041a, 0xB40);