#include "BehaviorUniqueAllocator.h"

class BehaviorUniqueAllocatorImplement : public BehaviorUniqueAllocator
{
public:
    int field_4;
    int field_8;
    int field_C;

};

static BehaviorUniqueAllocatorImplement *&g_pBehaviorUniqueAllocatorImplement = *(BehaviorUniqueAllocatorImplement**)(shared::base + 0x17E9BF0);
BehaviorUniqueAllocatorImplement *GetBehaviorUniqueAllocatorImplement()
{
    return ((BehaviorUniqueAllocatorImplement *(__cdecl *)())(shared::base + 0x68AFD0))();
}