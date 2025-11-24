#pragma once

#include <BehaviorAppBase.h>

class PlWig : public BehaviorAppBase
{
public:

    PlWig()
    {
        ((void(__thiscall *)(PlWig *))(shared::base + 0x6AB480))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9DD4);
};

VALIDATE_SIZE(PlWig, 0xA00);