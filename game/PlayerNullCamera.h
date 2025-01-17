#pragma once

#include <Behavior.h>

class PlayerNullCamera : public Behavior
{
public:
    float field_870;
    int field_874;
    int field_878;
    int field_87C;

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x17E9DD8);
};

VALIDATE_SIZE(PlayerNullCamera, 0x880);