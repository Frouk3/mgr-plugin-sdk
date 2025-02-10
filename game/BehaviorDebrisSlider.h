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
        ((void(__thiscall *)(BehaviorDebrisSlider *))(shared::base + 0x1DC040))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735328);
};

VALIDATE_SIZE(BehaviorDebrisSlider, 0x9B0);