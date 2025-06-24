#pragma once

#include <Behavior.h>
#include <Slot.h>

class Et3000 : public Behavior
{
public:
    class FreeObjectiveSlot : public Slot{};
public:
    int field_870;
    int field_874;
    int field_878;
    int field_87C;

    Et3000()
    {
        ((void(__thiscall *)(Et3000 *))(shared::base + 0x6A6AB0))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x1735348);
};

VALIDATE_SIZE(Et3000, 0x880);