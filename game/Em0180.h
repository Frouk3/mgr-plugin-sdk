#pragma once

#include <BehaviorEmBase.h>

class Em0180 : public BehaviorEmBase
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
    int field_DE0;
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
    int field_E20;
    int field_E24;
    int field_E28;
    int field_E2C;
    int field_E30;
    int field_E34;
    int field_E38;
    int field_E3C;
    int field_E40;
    int field_E44;
    int field_E48;
    int field_E4C;
    int field_E50;
    int field_E54;
    int field_E58;
    int field_E5C;
    int field_E60;
    int field_E64;
    int field_E68;
    int field_E6C;
    int field_E70;
    int field_E74;
    int field_E78;
    int field_E7C;
    int field_E80;
    int field_E84;
    int field_E88;
    int field_E8C;
    int field_E90;
    int field_E94;
    int field_E98;
    int field_E9C;
    int field_EA0;
    int field_EA4;
    int field_EA8;
    int field_EAC;
    int field_EB0;
    int field_EB4;
    int field_EB8;
    int field_EBC;
    int field_EC0;
    int field_EC4;
    int field_EC8;
    int field_ECC;
    int field_ED0;
    int field_ED4;
    int field_ED8;
    int field_EDC;
    int field_EE0;
    int field_EE4;
    int field_EE8;
    int field_EEC;
    int field_EF0;
    int field_EF4;
    int field_EF8;
    int field_EFC;
    int field_F00;
    int field_F04;
    int field_F08;
    int field_F0C;
    int field_F10;
    int field_F14;
    int field_F18;
    int field_F1C;
    int field_F20;
    int field_F24;
    int field_F28;
    int field_F2C;
    EntityHandle field_F30;
    int field_F34;
    int field_F38;
    int field_F3C;
    int field_F40;
    int field_F44;
    int field_F48;
    int field_F4C;
    int field_F50;
    int field_F54;
    int field_F58;
    int field_F5C;

    Em0180()
    {
        ((void(__thiscall *)(Em0180*))(shared::base + 0x6AF6E0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734EF4);
};

VALIDATE_SIZE(Em0180, 0xF60);