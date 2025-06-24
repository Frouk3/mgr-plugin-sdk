#pragma once

#include <cEspControler.h>
#include <BattleRegionManager.h>
#include <lib.h>

class BattleRegionManagerImplement : public BattleRegionManager
{
public:
    struct Unit
    {
        int m_ID;
        float m_TimeWeNeedThisObject;
    };
    lib::AllocatedArray<Unit>* m_Units;
    int field_8;
    int field_C;
    cEspControler field_10;
  
    static inline BattleRegionManagerImplement*& ms_Instance = *(BattleRegionManagerImplement**)(shared::base + 0x1734B00);

    static inline BattleRegionManagerImplement* get()
    {
        return ((BattleRegionManagerImplement *(__cdecl *)())(shared::base + 0x1110))();
    }
};

VALIDATE_SIZE(BattleRegionManagerImplement, 0xC0);