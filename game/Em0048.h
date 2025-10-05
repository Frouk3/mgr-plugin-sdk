#pragma once

#include <Behavior.h>

class Em0048 : public Behavior
{
public:
    Em0048()
    {
        ((void(__thiscall *)(Em0048*))(shared::base + 0x6A60A0))(this);
    }

    static inline Em0048* __cdecl allocate(Hw::cHeapVariable* allocator)
    {
        return ((Em0048 * (__cdecl *)(Hw::cHeapVariable*))(shared::base + 0x6A9FF0))(allocator);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x1735428);
};

VALIDATE_SIZE(Em0048, 0x870);