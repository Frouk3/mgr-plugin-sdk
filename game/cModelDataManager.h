#include "Hw.h"

struct cModelData
{

	struct ClsInfo;
	struct CutBoxInfo;
	struct CutInfo;
	struct ModelData;
};

struct cModelDataResource
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	float field_24;
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
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	int field_70;
	int field_74;
	int field_78;
	int field_7C;
	int field_80;
	int field_84;
	int field_88;
	int field_8C;
	int field_90;
	int field_94;
	int field_98;
	int field_9C;
	int field_A0;
	int field_A4;
	int field_A8;
	int field_AC;
	cModelData::CutInfo* m_pCutInfo;
	int field_B4;
};

struct cModelData::ClsInfo
{
	int* field_0;
	int m_nCapacity;
	int field_8;
};

struct cModelData::CutInfo
{
	cModelData::CutBoxInfo* m_pBoxInfo;
	int* field_4;
	int m_nCapacity;
	cModelData::ClsInfo* m_pClsInfo;
	int field_10;
};

struct cModelData::CutBoxInfo
{
	cVec4 m_vecMax;
	cVec4 m_vecMin;
	int m_nIndex;
	int field_24;
	int field_28;
	int field_2C;
};

struct cModelData::ModelData
{
	cVec4 m_vecMin;
	cVec4 m_vecMax;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	float field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	unsigned short* m_pBoneSet;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	int field_70;
	int field_74;
	int field_78;
	int field_7C;
	int field_80;
	int field_84;
	int field_88;
	int field_8C;
	int field_90;
	int field_94;
	int field_98;
	int field_9C;
	int field_A0;
	int field_A4;
	int field_A8;
	int field_AC;
	int field_B0;
	int field_B4;
	int field_B8;
	int field_BC;
	int field_C0;
	int field_C4;
	int field_C8;
	int field_CC;
	int field_D0;
	int field_D4;
	int field_D8;
	int field_DC;
	int field_E0;
	int field_E4;
	int field_E8;
	int field_EC;
	int field_F0;
	int field_F4;
	cModelDataResource* m_pResource;
};