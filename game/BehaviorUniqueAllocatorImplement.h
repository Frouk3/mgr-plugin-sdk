#include "BehaviorUniqueAllocator.h"
#include "shared.h"

class BehaviorUniqueAllocatorImplement : public BehaviorUniqueAllocator
{
public:
    int field_4;
    int field_8;
    int field_C;

    static inline BehaviorUniqueAllocatorImplement* Get()
    {
        return ((BehaviorUniqueAllocatorImplement *(__cdecl *)())(shared::base + 0x68AFD0))();
    }

    static inline BehaviorUniqueAllocatorImplement *&pInstance = *(BehaviorUniqueAllocatorImplement**)(shared::base + 0x17E9BF0);
};