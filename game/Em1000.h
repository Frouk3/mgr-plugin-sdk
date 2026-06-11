#pragma once

#include <Behavior.h>

class Em1000 : public Behavior
{
public:
    EntityHandle field_870;
    int field_874;
    int field_878;
    int field_87C;

    Em1000()
    {
        MAKE_CALL(shared::base + 0x6A66E0, void(__thiscall *)(Em1000 *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x17351DC);
};

VALIDATE_SIZE(Em1000, 0x880);