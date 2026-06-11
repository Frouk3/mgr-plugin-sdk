#pragma once

#include <AnimationMapManager.h>
#include <Hw.h>

class AnimationMapManagerImplement : public AnimationMapManager
{
public:
    Hw::cHeap *m_pHeap;
    Hw::cCriticalSection m_CriticalSection;
    int field_24;
    lib::AllocatedArray<AnimationMapResource *> *m_pAnimationMapResourceArray;
    int field_2C;

    void shutdown()
    {
        MAKE_CALL(shared::base + 0x4D8180, void(__thiscall *)(AnimationMapManagerImplement *), this);
    }

    static inline AnimationMapManagerImplement *get()
    {
        return MAKE_CALL(shared::base + 0x4D7570, AnimationMapManagerImplement*(__cdecl *)());
    }
};

inline AnimationMapManagerImplement*& g_AnimationMapManager = *(AnimationMapManagerImplement**)(shared::base + 0x1735BF4);

VALIDATE_SIZE(AnimationMapManagerImplement, 0x30);
VALIDATE_SIZE(AnimationMap::Unit, 0x3C);