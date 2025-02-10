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
        ((void(__thiscall *)(RayArmorDebris*))(shared::base + 0x6EF830))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x17E9CDC);
};

VALIDATE_SIZE(RayArmorDebris, 0x980);