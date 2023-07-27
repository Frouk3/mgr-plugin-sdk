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

  
};

extern BattleRegionManagerImplement*& g_pBattleRegionManagerImplement;
BattleRegionManagerImplement* GetBattleRegionManagerImplement();