#pragma once

#include <BehaviorWeapon.h>

class WpBaseDLC : public BehaviorWeapon
{
public:

    WpBaseDLC()
    {
        ((void(__thiscall *)(WpBaseDLC*))(shared::base + 0x6A74A0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9C44);
};

VALIDATE_SIZE(WpBaseDLC, 0x8C0);