#include "BattleSituationManagerImplement.h"
#include "shared.h"

BattleSituationManagerImplement* GetBattleSituationManagerImplement()
{
    return ((BattleSituationManagerImplement*(__cdecl*)())(shared::base + 0x972B30))();
}