#pragma once

#include <BehaviorBa.h>
#include <shared.h>

class AnimFlagObj : public BehaviorBa
{
public:

    AnimFlagObj()
    {
        ((void (__thiscall *)(AnimFlagObj *))(shared::base + 0x6B05A0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734B44);
};

VALIDATE_SIZE(AnimFlagObj, 0xB30);