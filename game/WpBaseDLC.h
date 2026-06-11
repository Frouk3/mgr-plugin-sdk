#pragma once

#include <BehaviorWeapon.h>

class WpBaseDLC : public BehaviorWeapon
{
public:

    WpBaseDLC()
    {
        MAKE_CALL(shared::base + 0x6A74A0, void(__thiscall *)(WpBaseDLC*), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x17E9C44);
};

VALIDATE_SIZE(WpBaseDLC, 0x8C0);