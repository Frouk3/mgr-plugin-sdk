#pragma once

#include "cActionMessageParts.h"
#include "cStageConnect.h"
#include "Pl0000.h"
#include "Pl1400.h"
#include "Pl1500.h"
#include "cDryCellGauge2.h"
#include "cEnergyGaugeWhiteRaiden.h"

class cGameUIManager
{
public:
  int field_4;
  int field_8;
  int field_C;
  int field_10;
  int field_14;
  cStageConnect* m_pStageConnect;
  int field_1C;
  int field_20;
  int field_24;
  int field_28;
  int field_2C;
  int field_30;
  int field_34;
  int field_38;
  int field_3C;
  int field_40;
  int field_44;
  int field_48;
  int field_4C;
  int field_50;
  int field_54;
  int field_58;
  int field_5C;
  Pl1500* m_pPlayer;
  cParts* m_pPlayerParts[13];
  Pl1500 *m_pPlayerInstance;
  EntityHandle m_nPlayerEntityHandle;
  cVec4 m_vecPlayerPosition;
  float field_B0;
  float field_B4;
  float field_B8;
  float field_BC;
  cActionMessageParts* m_pActionMessageParts;
  int field_C4;
  cDryCellGauge2* m_pcDryCellGauge2;
  cEnergyGaugeWhiteRaiden* m_pcEnergyGaugeWhiteRaiden;
  int field_D0;
  int field_D4;
  int field_D8;

  virtual ~cGameUIManager() {};
};

static cGameUIManager& g_cGameUIManager = *(cGameUIManager*)(shared::base + 0x19C1430);