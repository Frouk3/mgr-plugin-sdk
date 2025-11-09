#pragma once
#include <d3dx9.h>
#include "EntityHandle.h"

class Pl0000;

struct cCameraTypes
{
	Hw::cVec4 m_CamRot;
	EntityHandle m_PlayerHandle;
	Pl0000* m_pPlayer[2];
	float m_CurrentLerp;
	float m_TargetLerp;
	int field_24;
	float field_28;
	float field_2C;
	Hw::cMtx m_MulMtx;
};

VALIDATE_SIZE(cCameraTypes, 0x70);