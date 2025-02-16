#pragma once

#include <Behavior.h>

class RadarMapObj : public Behavior
{
public:

    RadarMapObj()
    {
        ((void(__thiscall *)(RadarMapObj *))(shared::base + 0x6A6D60))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735434);
};

VALIDATE_SIZE(RadarMapObj, 0x870);