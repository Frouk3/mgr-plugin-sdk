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
    Hw::CriticalSection field_10;
    int field_2C;

    BehaviorDatabaseImplement()
    {
        ((void (__thiscall *)(BehaviorDatabaseImplement *))(shared::base + 0x6C18F0))(this);
    }

    static inline BehaviorDatabaseImplement *&ms_Instance = *(BehaviorDatabaseImplement **)(shared::base + 0x17E9BF4);
    
    static inline BehaviorDatabaseImplement *get()
    {
        return ((BehaviorDatabaseImplement *(__cdecl *)())(shared::base + 0x68B0B0))();
    }
};

VALIDATE_SIZE(BehaviorDatabaseImplement, 0x30);