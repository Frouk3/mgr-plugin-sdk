#pragma once

#include <BehaviorBa.h>
#include <shared.h>

class AnimFlagObj : public BehaviorBa
{
public:

    AnimFlagObj()
    {
        MAKE_CALL(shared::base + 0x6B05A0, void(__thiscall *)(AnimFlagObj *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1734B44);
};

VALIDATE_SIZE(AnimFlagObj, 0xB30);