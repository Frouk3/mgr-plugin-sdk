#pragma once

#include "BattleCollisionManager.h"
#include "Slot.h"
#include "lib.h"
#include "Collision.h"

class BattleCollisionManagerImplement : public BattleCollisionManager
{
public:
    Hw::cHeapVariable *m_pHeapVariable;
    lib::StaticArray<Collision *, 128> *field_8;
    lib::StaticArray<Collision *, 128> *field_C;
    lib::StaticArray<Collision *, 1024> *field_10;
    lib::StaticArray<Collision *, 1024> *field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    struct MainUpdateForPauseSlot : Slot
    {

    } *m_pMainUpdateForPauseSlot;
    int field_3C;

    static inline BattleCollisionManagerImplement *&pInstance = *(BattleCollisionManagerImplement**)(shared::base + 0x19C52EC);
};