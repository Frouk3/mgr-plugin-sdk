#include "BehaviorUniqueAllocatorImplement.h"
#include "shared.h"

BehaviorUniqueAllocatorImplement *&g_pBehaviorUniqueAllocatorImplement = *(BehaviorUniqueAllocatorImplement**)(shared::base + 0x17E9BF0);

int BehaviorUniqueAllocatorImplement::Function0()
{
    return ReturnCallVMTFunc<int, 0, BehaviorUniqueAllocatorImplement*>(this);
}

int BehaviorUniqueAllocatorImplement::Function1()
{
    return ReturnCallVMTFunc<int, 1, BehaviorUniqueAllocatorImplement *>(this);
}

int BehaviorUniqueAllocatorImplement::Function2()
{
    return ReturnCallVMTFunc<int, 2, BehaviorUniqueAllocatorImplement*>(this);
}

int BehaviorUniqueAllocatorImplement::Function3()
{
    return ReturnCallVMTFunc<int, 3, BehaviorUniqueAllocatorImplement*>(this);
}

float BehaviorUniqueAllocatorImplement::Function4()
{
    return ReturnCallVMTFunc<float, 4, BehaviorUniqueAllocatorImplement*>(this);
}

BehaviorUniqueAllocatorImplement *GetBehaviorUniqueAllocatorImplement()
{
    return ((BehaviorUniqueAllocatorImplement *(__cdecl *)())(shared::base + 0x68AFD0))();
}
