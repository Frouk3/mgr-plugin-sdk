#pragma once

#include <BehaviorDebrisObject.h>

class BehaviorDebrisSlider : public BehaviorDebrisObject
{
public:
    int field_9A0;
    int field_9A4;
    int field_9A8;
    int field_9AC;

    BehaviorDebrisSlider()
    {
        MAKE_CALL(shared::base + 0x1DC040, void(__thiscall *)(BehaviorDebrisSlider *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1735328);
};

VALIDATE_SIZE(BehaviorDebrisSlider, 0x9B0);