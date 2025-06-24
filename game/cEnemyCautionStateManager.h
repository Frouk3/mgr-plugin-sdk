#pragma once

#include <Entity.h>

class cEnemyCautionStateManager
{
public:
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	float field_18;
	float field_1C;
	int field_20;
	float field_24;
	float field_28;
	float field_2C;
	float field_30;
	float field_34;
	float field_38;
	int m_nState;
	EntityHandle field_40;
	int field_44;
	int field_48;
	float field_4C;
	float field_50;
	int field_54;
	float field_58;
	float field_5C;
	float field_60;
	float field_64;
	float field_68;
	float field_6C;
	float field_70;
	float field_74;
	int field_78;
	float field_7C;
	float field_80;
	float field_84;
	float field_88;
	float field_8C;
	float field_90;
	float field_94;
	float field_98;
	int field_9C;
	float field_A0;
	float field_A4;
	float field_A8;
	float field_AC;
	float field_B0;
	float field_B4;
	float field_B8;
	float field_BC;
	int field_C0;
	float field_C4;
	float field_C8;
	float field_CC;
	float field_D0;
	float field_D4;
	float field_D8;
	float field_DC;
	float field_E0;
	int field_E4;
	float field_E8;
	float field_EC;
	float field_F0;
	float field_F4;
	float field_F8;
	float field_FC;
	float field_100;
	float field_104;
	float field_108;
	int field_10C;
	int field_110;
	int field_114;
	int field_118;
	float field_11C;
	cVec4 m_vecSpotPos;
	EntityHandle m_SpottedEntity;
	int field_134;
	int field_138;
	int field_13C;

	virtual ~cEnemyCautionStateManager() {};
};

VALIDATE_SIZE(cEnemyCautionStateManager, 0x140);