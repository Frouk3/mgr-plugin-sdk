#pragma once

#include <BehaviorBulletBase.h>

class BulletBaseDLC : public BehaviorBulletBase
{
public:

    BulletBaseDLC()
    {
        MAKE_CALL(shared::base + 0x6B6190, void(__thiscall *)(BulletBaseDLC *), this);
    }

    static inline ContextInstance &m_Context = *(ContextInstance*)(shared::base + 0x17E9C48);
};

VALIDATE_SIZE(BulletBaseDLC, 0x1210);