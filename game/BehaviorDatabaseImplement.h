#pragma once

#include <BehaviorDatabase.h>
#include <Behavior.h>
#include <lib.h>

class BehaviorData;

class BehaviorDatabaseImplement : public BehaviorDatabase
{
public:
    struct UsedContainer
    {
        int field_0;
        int field_4;
        int field_8;
    };
    lib::AllocatedArray<BehaviorDatabaseImplement::UsedContainer> *m_UsedContainers;
    lib::StaticArray<BehaviorData *, 2048> *m_BehaviorData;
    int field_C;
    Hw::cCriticalSection field_10;
    int field_2C;

    BehaviorDatabaseImplement()
    {
        MAKE_CALL(shared::base + 0x6C18F0, void(__thiscall *)(BehaviorDatabaseImplement *), this);
    }
    
    static inline BehaviorDatabaseImplement *get()
    {
        return MAKE_CALL(shared::base + 0x68B0B0, BehaviorDatabaseImplement *(__cdecl *)());
    }
};

inline BehaviorDatabaseImplement *&g_BehaviorDatabase = *(BehaviorDatabaseImplement **)(shared::base + 0x17E9BF4);

VALIDATE_SIZE(BehaviorDatabaseImplement, 0x30);