#pragma once

#include <BehaviorAppBase.h>

class PlWig : public BehaviorAppBase
{
public:

    PlWig()
    {
        MAKE_CALL(shared::base + 0x6AB480, void (__thiscall *)(PlWig *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x17E9DD4);
};

VALIDATE_SIZE(PlWig, 0xA00);