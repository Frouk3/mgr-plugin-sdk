#pragma once
#include "Hw.h"

class cCameraViewProj : public Hw::CameraProj, public Hw::cCameraBase
{
public:
	D3DXMATRIX field_200;
	D3DXMATRIX field_240;
	D3DXMATRIX field_280;
};

VALIDATE_SIZE(cCameraViewProj, 0x2C0);
