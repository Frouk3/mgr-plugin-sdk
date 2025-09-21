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
    lib::StaticArray<Collision *, 128> *m_pOffenseCollisions;
    lib::StaticArray<Collision *, 128> *field_C;
    lib::StaticArray<Collision *, 1024> *m_pDefenseCollisions;
    lib::StaticArray<Collision *, 1024> *field_14;
    Hw::CriticalSection m_CriticalSection;
    int field_34;
    class MainUpdateForPauseSlot : public Slot
    {

    } *m_pMainUpdateForPauseSlot;
    int field_3C;

    // vft start

    void addOffense(Collision *pCollision)
    {
        CallVMTFunc<2, BattleCollisionManagerImplement*, Collision*>(this, pCollision);
    }

    void addDefense(Collision *pCollision)
    {
        CallVMTFunc<3, BattleCollisionManagerImplement*, Collision*>(this, pCollision);
    }

    void removeOffense(Collision *pCollision)
    {
        CallVMTFunc<4, BattleCollisionManagerImplement*, Collision*>(this, pCollision);
    }

    void removeDefense(Collision *pCollision)
    {
        CallVMTFunc<5, BattleCollisionManagerImplement*, Collision*>(this, pCollision);
    }

    Collision *getOffenseByUniqueID(int uniqueID)
    {
        return ReturnCallVMTFunc<Collision*, 6, BattleCollisionManagerImplement*, int>(this, uniqueID);
    }

    size_t getOffenseCount()
    {
        return ReturnCallVMTFunc<size_t, 13, BattleCollisionManagerImplement*>(this);
    }

    size_t getDefenseCount()
    {
        return ReturnCallVMTFunc<size_t, 14, BattleCollisionManagerImplement*>(this);
    }

    Collision *getOffenseCollision(size_t index) // index == array index
    {
        return ReturnCallVMTFunc<Collision*, 15, BattleCollisionManagerImplement*, size_t>(this, index);
    }

    Collision *getDefenseCollision(size_t index) // index == array index
    {
        return ReturnCallVMTFunc<Collision*, 16, BattleCollisionManagerImplement*, size_t>(this, index);
    }

    // vft end

    BattleCollisionManagerImplement(Hw::cHeapVariable *pAllocator)
    {
        ((void(__thiscall *)(BattleCollisionManagerImplement*, Hw::cHeapVariable*))(shared::base + 0x97B2C0))(this, pAllocator);
    }

    ~BattleCollisionManagerImplement()
    {
        ((void(__thiscall *)(BattleCollisionManagerImplement*))(shared::base + 0x97B9C0))(this);
    }

    static inline BattleCollisionManagerImplement *&ms_Instance = *(BattleCollisionManagerImplement**)(shared::base + 0x19C52EC);
};

VALIDATE_SIZE(BattleCollisionManagerImplement, 0x40);