#pragma once

#include <BehaviorBulletBase.h>

class BulletBaseDLC : public BehaviorBulletBase
{
public:

    BulletBaseDLC()
    {
        ((void(__thiscall *)(BulletBaseDLC *))(shared::base + 0x6B6190))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x17E9C48);
};

VALIDATE_SIZE(BulletBaseDLC, 0x1210);