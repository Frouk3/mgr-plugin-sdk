#pragma once

#include <BattleCollisionManager.h>
#include <Slot.h>
#include <lib.h>
#include <Collision.h>
#include <Hw.h>

class BattleCollisionManagerImplement : public BattleCollisionManager
{
public:
    Hw::cHeap *m_pHeap;
    lib::StaticArray<Collision *, 128> *m_pOffenseCollisions;
    lib::StaticArray<Collision *, 128> *field_C;
    lib::StaticArray<Collision *, 1024> *m_pDefenseCollisions;
    lib::StaticArray<Collision *, 1024> *field_14;
    Hw::cCriticalSection m_CriticalSection;
    int field_34;
    class MainUpdateForPauseSlot : public Slot
    {

    } *m_pMainUpdateForPauseSlot;
    int field_3C;

    // vft start

    void addOffense(Collision *pCollision)
    {
        MAKE_VCALL(2, void(__thiscall *)(BattleCollisionManagerImplement *, Collision *), this, pCollision);
    }

    void addDefense(Collision *pCollision)
    {
        MAKE_VCALL(3, void(__thiscall *)(BattleCollisionManagerImplement *, Collision *), this, pCollision);
    }

    void removeOffense(Collision *pCollision)
    {
        MAKE_VCALL(4, void(__thiscall *)(BattleCollisionManagerImplement *, Collision *), this, pCollision);
    }

    void removeDefense(Collision *pCollision)
    {
        MAKE_VCALL(5, void(__thiscall *)(BattleCollisionManagerImplement *, Collision *), this, pCollision);
    }

    Collision *getOffenseByUniqueID(int uniqueID)
    {
        return MAKE_VCALL(6, Collision *(__thiscall *)(BattleCollisionManagerImplement *, int), this, uniqueID);
    }

    size_t getOffenseCount()
    {
        return MAKE_VCALL(13, size_t(__thiscall *)(BattleCollisionManagerImplement *), this);
    }

    size_t getDefenseCount()
    {
        return MAKE_VCALL(14, size_t(__thiscall *)(BattleCollisionManagerImplement *), this);
    }

    Collision *getOffenseCollision(size_t index) // index == array index
    {
        return MAKE_VCALL(15, Collision *(__thiscall *)(BattleCollisionManagerImplement *, size_t), this, index);
    }

    Collision *getDefenseCollision(size_t index) // index == array index
    {
        return MAKE_VCALL(16, Collision *(__thiscall *)(BattleCollisionManagerImplement *, size_t), this, index);
    }

    // vft end

    BattleCollisionManagerImplement(Hw::cHeapVariable *pAllocator)
    {
        MAKE_CALL(shared::base + 0x97B2C0, void(__thiscall *)(BattleCollisionManagerImplement*, Hw::cHeapVariable*), this, pAllocator);
    }

    ~BattleCollisionManagerImplement()
    {
        MAKE_CALL(shared::base + 0x97B9C0, void(__thiscall *)(BattleCollisionManagerImplement*), this);
    }
};

inline BattleCollisionManagerImplement *&g_BattleCollisionManager = *(BattleCollisionManagerImplement**)(shared::base + 0x19C52EC);

VALIDATE_SIZE(BattleCollisionManagerImplement, 0x40);