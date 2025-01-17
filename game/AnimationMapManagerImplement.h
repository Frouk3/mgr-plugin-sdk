#pragma once

#include <AnimationMapManager.h>
#include <Hw.h>

class AnimationMapManagerImplement : public AnimationMapManager
{
public:
    Hw::cHeapVariable *m_Allocator;
    Hw::CriticalSection field_8;
    int field_24;
    lib::AllocatedArray<AnimationMapResource *> *m_pAnimationMapResourceArray;
    int field_2C;

    void shutdown()
    {
        ((void(__thiscall *)(AnimationMapManagerImplement *))(shared::base + 0x4D8180))(this);
    }

    static inline AnimationMapManagerImplement*& pInstance = *(AnimationMapManagerImplement**)(shared::base + 0x1735BF4);
};

VALIDATE_SIZE(AnimationMapManagerImplement, 0x30);
VALIDATE_SIZE(AnimationMap::Unit, 0x3C);