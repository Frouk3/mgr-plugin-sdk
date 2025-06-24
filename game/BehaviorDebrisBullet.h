#pragma once

#include <BehaviorDebrisBase.h>

class BehaviorDebrisBullet : public BehaviorDebrisBase
{
public:
    int field_970;
    int field_974;
    int field_978;
    int field_97C;

    BehaviorDebrisBullet()
    {
        ((void(__thiscall *)(BehaviorDebrisBullet *))(shared::base + 0x1DBE70))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735320);  
};

VALIDATE_SIZE(BehaviorDebrisBullet, 0x980);