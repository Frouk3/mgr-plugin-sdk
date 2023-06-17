#include "BehaviorUniqueAllocatorImplement.h"
#include "shared.h"

BehaviorUniqueAllocatorImplement *&g_pBehaviorUniqueAllocatorImplement = *(BehaviorUniqueAllocatorImplement**)(shared::base + 0x17E9BF0);

int BehaviorUniqueAllocatorImplement::Function0()
{
    return CallVMTFunc<int, 0, BehaviorUniqueAllocatorImplement*>(this);
}

int BehaviorUniqueAllocatorImplement::Function1()
{
    return CallVMTFunc<int, 1, BehaviorUniqueAllocatorImplement *>(this);
}

int BehaviorUniqueAllocatorImplement::Function2()
{
    return CallVMTFunc<int, 2, BehaviorUniqueAllocatorImplement*>(this);
}

int BehaviorUniqueAllocatorImplement::Function3()
{
    return CallVMTFunc<int, 3, BehaviorUniqueAllocatorImplement*>(this);
}

float BehaviorUniqueAllocatorImplement::Function4()
{
    return CallVMTFunc<float, 4, BehaviorUniqueAllocatorImplement*>(this);
}

BehaviorUniqueAllocatorImplement *GetBehaviorUniqueAllocatorImplement()
{
    return ((BehaviorUniqueAllocatorImplement *(__cdecl *)())(shared::base + 0x68AFD0))();
}
