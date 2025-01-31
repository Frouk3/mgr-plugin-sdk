#pragma once

#include <BattleCollisionManager.h>
#include <Slot.h>
#include <lib.h>
#include <Collision.h>
#include <Hw.h>

class BattleCollisionManagerImplement : public BattleCollisionManager
{
public:
    Hw::cHeapVariable *m_Allocator;
    lib::StaticArray<Collision *, 128> *field_8;
    lib::StaticArray<Collision *, 128> *field_C;
    lib::StaticArray<Collision *, 1024> *field_10;
    lib::StaticArray<Collision *, 1024> *field_14;
    Hw::CriticalSection m_CriticalSection;
    int field_34;
    struct MainUpdateForPauseSlot : public Slot
    {

    } *m_MainUpdateForPauseSlot;
    int field_3C;

    static inline BattleCollisionManagerImplement *&ms_Instance = *(BattleCollisionManagerImplement**)(shared::base + 0x19C52EC);
};

VALIDATE_SIZE(BattleCollisionManagerImplement, 0x40);