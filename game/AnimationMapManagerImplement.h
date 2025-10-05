#pragma once

#include <AnimationMapManager.h>
#include <Hw.h>

class AnimationMapManagerImplement : public AnimationMapManager
{
public:
    Hw::cHeapVariable *m_pAllocator;
    Hw::CriticalSection m_criticalSection;
    int field_24;
    lib::AllocatedArray<AnimationMapResource *> *m_pAnimationMapResourceArray;
    int field_2C;

    void shutdown()
    {
        ((void(__thiscall *)(AnimationMapManagerImplement *))(shared::base + 0x4D8180))(this);
    }

    AnimationMapManagerImplement *get()
    {
        return ((AnimationMapManagerImplement *(__cdecl *)())(shared::base + 0x4D7570))(); // I want to say that they're using singleton pattern here, but it isn't true singleton
    }

    static inline AnimationMapManagerImplement*& ms_pInstance = *(AnimationMapManagerImplement**)(shared::base + 0x1735BF4);
};

VALIDATE_SIZE(AnimationMapManagerImplement, 0x30);
VALIDATE_SIZE(AnimationMap::Unit, 0x3C);