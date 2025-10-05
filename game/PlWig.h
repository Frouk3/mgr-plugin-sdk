#pragma once

#include <BehaviorAppBase.h>

class PlWig : public BehaviorAppBase
{
public:

    PlWig()
    {
        ((void(__thiscall *)(PlWig *))(shared::base + 0x6AB480))(this);
    }

    static inline PlWig *__cdecl allocate(Hw::cHeapVariable *allocator)
    {
        return ((PlWig * (__cdecl*)(Hw::cHeapVariable*))(shared::base + 0x6BCB20))(allocator);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9DD4);
};

VALIDATE_SIZE(PlWig, 0xA00);