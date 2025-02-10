#pragma once

#include <BehaviorAppBase.h>
#include <EntitySystem.h>

class Et002f : public BehaviorAppBase
{
public:
    EntitySystem::SetInfo field_A00;
    int field_B18;
    int field_B1C;
    int field_B20;
    int field_B24;
    int field_B28;
    int field_B2C;
    int field_B30;
    int field_B34;
    int field_B38;
    int field_B3C;
    int field_B40;
    int field_B44;
    int field_B48;
    int field_B4C;
    int field_B50;
    int field_B54;
    int field_B58;
    int field_B5C;
    int field_B60;
    int field_B64;
    int field_B68;
    int field_B6C;
    int field_B70;
    int field_B74;
    int field_B78;
    int field_B7C;
    int field_B80;
    int field_B84;
    int field_B88;
    int field_B8C;
    int field_B90;
    int field_B94;
    int field_B98;
    int field_B9C;
    int field_BA0;
    int field_BA4;
    int field_BA8;
    int field_BAC;
    int field_BB0;
    int field_BB4;
    int field_BB8;
    int field_BBC;
    cEspControler field_BC0;
    cEspControler field_C70;
    int field_D20;
    int field_D24;
    int field_D28;
    int field_D2C;

    Et002f()
    {
        ((void(__thiscall *)(Et002f*))(shared::base + 0x6AF850))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17352A8);
};

VALIDATE_SIZE(Et002f, 0xD30);