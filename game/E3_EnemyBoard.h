#pragma once

#include <BehaviorEmBase.h>

class E3_EnemyBoard : public BehaviorEmBase
{
public:
    int field_DB8;
    int field_DBC;
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
    lib::StaticArray<Entity *, 3> m_Board;
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
    EntitySystem::SetInfo field_E60;
    int field_F78;
    int field_F7C;
};