#pragma once

#include <BehaviorAppBase.h>

class Pl0013 : public BehaviorAppBase
{
public:
    int field_A00;
    int field_A04;
    int field_A08;
    int field_A0C;
    cEspControler field_A10;
    
    Pl0013()
    {
        ((void(__thiscall *)(Pl0013 *))(shared::base + 0x6AB520))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9D80);
};

VALIDATE_SIZE(Pl0013, 0xAC0);