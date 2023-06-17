#include "BehaviorDatabaseImplement.h"
#include "shared.h"

BehaviorDatabaseImplement *&g_pBehaviorDatabaseImplement = *(BehaviorDatabaseImplement **)(shared::base + 0x17E9BF4);

int BehaviorDatabaseImplement::Function0(int a2)
{
    return CallVMTFunc<int, 0, BehaviorDatabaseImplement *, int>(this, a2);
}

int BehaviorDatabaseImplement::Function1(int a2)
{
    return CallVMTFunc<int, 1, BehaviorDatabaseImplement *, int>(this, a2);
}

void BehaviorDatabaseImplement::Function2(float a2)
{
    CallVMTFunc<2, BehaviorDatabaseImplement*, float>(this, a2);
}

int BehaviorDatabaseImplement::Function3()
{
    return CallVMTFunc<int, 3, BehaviorDatabaseImplement *>(this);
}

void BehaviorDatabaseImplement::Function4(int a2, int a3)
{
    CallVMTFunc<4, BehaviorDatabaseImplement *, int, int>(this, a2, a3);
}

BehaviorDatabaseImplement *GetBehaviorDatabaseImplement()
{
    return ((BehaviorDatabaseImplement *(__cdecl *)())(shared::base + 0x68B0B0))();
};
