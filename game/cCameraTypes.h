#pragma once
#include <d3dx9.h>
#include "EntityHandle.h"

class Pl0000;

struct cCameraTypes
{
	float m_fVerticalAngle; // pitch
	float m_fHorizontalAngle; // yaw
	int m_fZAngle;
	int field_C;
	EntityHandle m_nPlayerHandle;
	Pl0000* m_pPlayer[2];
	float field_1C;
	float field_20;
	int field_24;
	float field_28;
	int field_2C;
	D3DXMATRIX field_30;
};

VALIDATE_SIZE(cCameraTypes, 0x70);