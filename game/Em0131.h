#pragma once

#include <EmBaseDLC.h>
#include <RayArmorDebris.h>

class Em0131Debris : public RayArmorDebris
{
public:
    int field_980;
    int field_984;
    int field_988;
    int field_98C;
    int field_990;
    int field_994;
    int field_998;
    int field_99C;
    int field_9A0;
    int field_9A4;
    int field_9A8;
    int field_9AC;

    Em0131Debris()
    {
        ((void(__thiscall *)(Em0131Debris *))(shared::base + 0x6B5B00))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735524);
};

class Em0131 : public EmBaseDLC
{
public:
    int field_E8C;
    int field_E90;
    EntityHandle field_E94;
    EntityHandle field_E98;
    int field_E9C;
    
    Em0131()
    {
        ((void(__thiscall *)(Em0131*))(shared::base + 0x6B5950))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735520);
};

VALIDATE_SIZE(Em0131Debris, 0x9B0);
VALIDATE_SIZE(Em0131, 0xEA0);