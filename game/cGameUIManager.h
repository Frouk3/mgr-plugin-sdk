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
	Hw::cFixedVector<void*> field_30;
	Hw::cFixedVector<void*> field_44;
	Entity *m_pPlayerEntity;
	EntityHandle m_PlayerHandle;
	Pl1500 *m_pPlCharacter;
	cParts *m_pPlayerParts[13];
	Pl1500 *m_pPlayer;
	int m_nPlayerEntityHandle;
	cVec4 m_vecPlayerPosition;
	cVec4 field_B0;
	cActionMessageParts *m_pActionMessageParts;
	int field_C4;
	cDryCellGauge2 *m_pcDryCellGauge2;
	int field_CC;
	cRadarMap *m_pRadarMap;
	cWeaponInfoDispParts *m_pWeaponInfoDispParts;
	int field_D8;

	virtual ~cGameUIManager() {};

	static inline cGameUIManager& ms_Instance = *(cGameUIManager*)(shared::base + 0x19C1430);
};

VALIDATE_SIZE(cGameUIManager, 0xDC);