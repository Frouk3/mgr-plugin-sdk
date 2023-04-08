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

  virtual void Function0(float a2) = 0;
  virtual int Function1(int ArgList) = 0;
  virtual int __fastcall Function2(int edx0, int a3) = 0;
  virtual int __stdcall Function3(char ArgList) = 0;
  virtual void Function4() = 0;
  virtual ~BattleRegionManagerImplement() override {};
};

extern BattleRegionManagerImplement*& g_pBattleRegionManagerImplement;
BattleRegionManagerImplement* GetBattleRegionManagerImplement();