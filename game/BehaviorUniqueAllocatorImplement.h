#pragma once

#include <BehaviorUniqueAllocator.h>
#include <shared.h>
#include <Hw.h>

class BehaviorUniqueAllocatorImplement : public BehaviorUniqueAllocator
{
public:
    struct Data
    {
        struct BehaviorData
        {
            int m_Index;
            int field_4;
            Hw::cCriticalSection m_Section;
            int field_24;
        };
    };

    struct AllocationData
    {
        Data::BehaviorData *m_BehaviorData;
        Data::BehaviorData **m_DataReferences;
        int m_FreeDatas;
    };

    AllocationData m_AllocData; // Useless

    static inline BehaviorUniqueAllocatorImplement* get()
    {
        return MAKE_CALL(shared::base + 0x68AFD0, BehaviorUniqueAllocatorImplement *(__cdecl *)());
    }
};

inline BehaviorUniqueAllocatorImplement *&g_BehaviorUniqueAllocator = *(BehaviorUniqueAllocatorImplement**)(shared::base + 0x17E9BF0);