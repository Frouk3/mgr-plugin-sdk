#pragma once

#include <BehaviorWeapon.h>

class cPl0000Weapon : public BehaviorWeapon
{
public:
    int field_8C0;
    int field_8C4;
    int field_8C8;
    int field_8CC;
    cEspControler field_8D0;
    
    cPl0000Weapon()
    {
        ((void(__thiscall *)(cPl0000Weapon *))(shared::base + 0x6A6880))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9DBC);
};

VALIDATE_SIZE(cPl0000Weapon, 0x980);