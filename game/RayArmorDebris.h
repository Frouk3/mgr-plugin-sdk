#pragma once

#include <BehaviorDebrisBase.h>

class RayArmorDebris : public BehaviorDebrisBase
{
public:
    int field_970;
    int field_974;
    int field_978;
    int field_97C;

    RayArmorDebris()
    {
        MAKE_CALL(shared::base + 0x6EF830, void (__thiscall *)(RayArmorDebris *), this);
    }

    static inline ContextInstance &m_Context = *(ContextInstance*)(shared::base + 0x17E9CDC);
};

VALIDATE_SIZE(RayArmorDebris, 0x980);