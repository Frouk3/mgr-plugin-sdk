#pragma once

#include "cEspControler.h"
#include "BattleRegionManager.h"

class BattleRegionManagerImplement : public BattleRegionManager
{
public:
    int field_4;
    int field_8;
    int field_C;
    cEspControler field_10;
  
    static inline BattleRegionManagerImplement*& pInstance = *(BattleRegionManagerImplement**)(shared::base + 0x1734B00);

    static inline BattleRegionManagerImplement* Get()
    {
        return ((BattleRegionManagerImplement *(__cdecl *)())(shared::base + 0x1110))();
    }
};