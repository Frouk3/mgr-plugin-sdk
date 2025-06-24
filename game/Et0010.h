#pragma once

#include <BehaviorEmBase.h>

class Et0010 : public BehaviorEmBase
{
public:
    int field_DC0;
    int field_DC4;
    int field_DC8;
    int field_DCC;
    int field_DD0;
    int field_DD4;
    int field_DD8;
    int field_DDC;
    EntityHandle field_DE0;
    int field_DE4;
    int field_DE8;
    int field_DEC;
    int field_DF0;
    int field_DF4;
    int field_DF8;
    int field_DFC;
    int field_E00;
    int field_E04;
    int field_E08;
    int field_E0C;
    int field_E10;
    int field_E14;
    int field_E18;
    int field_E1C;
    EntitySystem::SetInfo field_E20;
    int field_F38;
    int field_F3C;

    Et0010()
    {
        ((void(__thiscall *)(Et0010*))(shared::base + 0x6AF400))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17352A4);
};

VALIDATE_SIZE(Et0010, 0xF40);