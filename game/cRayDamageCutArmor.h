#pragma once

#include <cRayArmor.h>

class cRayDamageCutArmor : public cRayArmor
{
public:
    int field_A60;
    int field_A64;
    int field_A68;
    int field_A6C;
    int field_A70;
    int field_A74;
    int field_A78;
    int field_A7C;
    int field_A80;
    int field_A84;
    int field_A88;
    int field_A8C;

    cRayDamageCutArmor()
    {
        ((void(__thiscall *)(cRayDamageCutArmor *))(shared::base + 0x6C0E90))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9CE0);
};

VALIDATE_SIZE(cRayDamageCutArmor, 0xA90);