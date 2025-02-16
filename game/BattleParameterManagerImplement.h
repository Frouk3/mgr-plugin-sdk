#pragma once

#include <BattleParameterManager.h>
#include <Hw.h>
#include <lib.h>

struct BattleParameterResource
{
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

class BattleParameterManagerImplement : public BattleParameterManager
{
public:
    Hw::cHeapVariable *m_Allocator;
    Hw::CriticalSection field_8;
    int field_24;
    lib::AllocatedArray<BattleParameterResource *> *m_BattleParameterResources;
    int field_2C;

    static inline BattleParameterManagerImplement*& ms_Instance = *(BattleParameterManagerImplement**)(shared::base + 0x19C5260);
};

VALIDATE_SIZE(BattleParameterManagerImplement, 0x30);