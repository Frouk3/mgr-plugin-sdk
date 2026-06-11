#pragma once

#include <Behavior.h>

class RadarMapObj : public Behavior
{
public:

    RadarMapObj()
    {
        MAKE_CALL(shared::base + 0x6A6D60, void (__thiscall *)(RadarMapObj *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x1735434);
};

VALIDATE_SIZE(RadarMapObj, 0x870);