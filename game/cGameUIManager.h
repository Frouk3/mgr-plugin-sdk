#pragma once

#include <cActionMessageParts.h>
#include <cStageConnect.h>
#include <Pl0000.h>
#include <Pl1400.h>
#include <Pl1500.h>
#include <cDryCellGauge2.h>
#include <cEnergyGaugeWhiteRaiden.h>
#include <cZandatsuTarget.h>
#include <cRadarMap.h>
#include <cWeaponInfoDispParts.h>

class cGameUIManager
{
public:
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	cStageConnect *m_pStageConnect;
	Hw::cFixedVector<cZandatsuTarget> m_ZandatsuTargets;
	int field_30; // Hw::cFixedVector but typename is not defined -> m_Enemies(?)
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44; // Hw::cFixedVector but typename is not defined
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	Entity *m_pPlayerEntity;
	EntityHandle m_nEntityHandle;
	Pl1500 *m_pPlCharacter;
	cParts *m_pPlayerParts[13];
	Pl1500 *m_pPlayer;
	int m_nPlayerEntityHandle;
	cVec4 m_vecPlayerPosition;
	cVec4 field_B0;
	cActionMessageParts *m_pcActionMessageParts;
	int field_C4;
	cDryCellGauge2 *m_pcDryCellGauge2;
	int field_CC;
	cRadarMap *m_pRadarMap;
	cWeaponInfoDispParts *m_pcWeaponInfoDispParts;
	int field_D8;

	virtual ~cGameUIManager() {};

	static inline cGameUIManager& Instance = *(cGameUIManager*)(shared::base + 0x19C1430);
};

VALIDATE_SIZE(cGameUIManager, 0xDC);