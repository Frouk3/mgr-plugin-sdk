#pragma once

#include <Behavior.h>

class Em0310QteDummy : public Behavior
{
public:
    EntityHandle field_870;
    int field_874;
    int field_878;
    int field_87C;

    Em0310QteDummy()
    {
        ((void(__thiscall *)(Em0310QteDummy *))(shared::base + 0x6A6440))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x173515C);
};

VALIDATE_SIZE(Em0310QteDummy, 0x880);