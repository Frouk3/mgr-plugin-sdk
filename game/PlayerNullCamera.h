#pragma once

#include <Behavior.h>

class PlayerNullCamera : public Behavior
{
public:
    float field_870;
    int field_874;
    int field_878;
    int field_87C;

    PlayerNullCamera()
    {
        MAKE_CALL(shared::base + 0x6A60D0, void (__thiscall *)(PlayerNullCamera *), this);
    }

    static inline ContextInstance &m_Context = *(ContextInstance*)(shared::base + 0x17E9DD8);
};

VALIDATE_SIZE(PlayerNullCamera, 0x880);