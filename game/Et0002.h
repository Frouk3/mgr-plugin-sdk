#pragma once

#include <Behavior.h>

class Et0002 : public Behavior
{
public:
    int field_870;
    int field_874;
    int field_878;
    int field_87C;

    Et0002()
    {
        MAKE_CALL(shared::base + 0x6A6960, void(__thiscall *)(Et0002 *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1735220);
};

VALIDATE_SIZE(Et0002, 0x880);