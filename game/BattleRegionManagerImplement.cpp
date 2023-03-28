#include "BattleRegionManagerImplement.h"
#include "shared.h"

BattleRegionManagerImplement *GetBattleRegionManagerImplement()
{
    return ((BattleRegionManagerImplement *(__cdecl *)())(shared::base + 0x1110))();
}

BattleRegionManagerImplement*& g_pBattleRegionManagerImplement = *(BattleRegionManagerImplement**)(shared::base + 0x1734B00);