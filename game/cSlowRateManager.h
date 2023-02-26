#pragma once
#include "cSlowRateUnit.h"
#include "Hw.h"

class cSlowRateManager
{
public:
  int field_4;
  int field_8;
  int field_C;
  int field_10;
  int field_14;
  int field_18;
  int field_1C;
  Hw::cHeapVariable* m_pHeapVariable;
  int field_24;
  int field_28;
  int field_2C;
  int field_30;
  int field_34;
  int field_38;
  struct {
		float m_fRate;
		float m_fDefaultRate;
		float m_fActualRate;
		float m_fCalculatedRate;
	} m_fSlowRate[4];
  float m_fTickRate;
  float m_fTicks;
  float field_84;
  float field_88;
  float field_8C;
  float field_90;

  virtual ~cSlowRateManager() {};
  cSlowRateManager();
  void SetSlowRate(int SlowRateType, float SlowRate);
  float GetSlowRate(int SlowRateType);
  void ResetSlowRate();
  void Cleanup();
  cSlowRateUnit *AllocUnit();
};

void cSlowRateManager_Reset();
void cSlowRateManager_SetSlowRate(int SlowRateType, float SlowRate);
cSlowRateManager* GetcSlowRateManager();

extern cSlowRateManager& g_cSlowRateManager;
extern cSlowRateManager*& g_pcSlowRateManager;