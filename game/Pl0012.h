#pragma once

#include <Behavior.h>

class Pl0012 : public Behavior
{
public:
    int field_870;
    int field_874;
    int field_878;
    int field_87C;
    cEspControler field_880;
    int field_930;
    float field_934;
    int field_938;
    int field_93C;

    Pl0012()
    {
        ((void(__thiscall *)(Pl0012 *))(shared::base + 0x6A6040))(this);
    }

    static inline Pl0012 *__cdecl allocate(Hw::cHeapVariable *allocator)
    {
        return ((Pl0012* (__cdecl *)(Hw::cHeapVariable *))(shared::base + 0x6A9F60))(allocator);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9F20);
};

VALIDATE_SIZE(Pl0012, 0x940);