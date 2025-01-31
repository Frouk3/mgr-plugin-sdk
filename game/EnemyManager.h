#pragma once

#include <cEnemyInfoManager.h>
#include <BehaviorEmBase.h>

struct EnemyManager
{
    int field_0;
    int field_4;
    Hw::CriticalSection m_ManagerSection;
    int field_24;
    Hw::cFixedList<EntityHandle> m_EnemyList;
    float field_44;
    float field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
};