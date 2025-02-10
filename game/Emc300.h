#pragma once

#include <EmBaseDLC.h>

class Emc300 : public EmBaseDLC
{
public:
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

    Emc300()
    {
        ((void(__thiscall *)(Emc300 *))(shared::base + 0x6B1540))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1735A30);
};

VALIDATE_SIZE(Emc300, 0xED0);