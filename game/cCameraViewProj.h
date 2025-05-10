#pragma once
#include "Hw.h"

class cCameraViewProj : public Hw::CameraProj, public Hw::cCameraBase
{
public:
	D3DXMATRIX field_200;
	D3DXMATRIX field_240;
	D3DXMATRIX field_280;

	void screenToWorld(cVec4& out, const cVec4& ScreenPos, const D3DXMATRIX &viewMatrix, int __unused)
	{
		((void(__thiscall *)(cCameraViewProj*, cVec4&, const cVec4&, const D3DXMATRIX&, int))(shared::base + 0x9E4E40))(this, out, ScreenPos, viewMatrix, __unused);
	}

	void screenToWorld(cVec4& out, const cVec4& ScreenPos, const D3DXMATRIX &viewMatrix)
	{
		((void(__thiscall *)(cCameraViewProj*, cVec4&, const cVec4&, const D3DXMATRIX&))(shared::base + 0x9E4DC0))(this, out, ScreenPos, viewMatrix);
	}

	BOOL worldToScreen(cVec4& out, const cVec4& WorldPos, const D3DXMATRIX& matrix, float farZ)
	{
		return ((BOOL(__thiscall *)(cCameraViewProj*, cVec4&, const cVec4&, const D3DXMATRIX&, float))(shared::base + 0x9E5B60))(this, out, WorldPos, matrix, farZ);
	}

	BOOL worldToScreen(cVec4& out, const cVec4& WorldPos, const D3DXMATRIX& matrix, int __unused, float farZ)
	{
		return ((BOOL(__thiscall *)(cCameraViewProj*, cVec4&, const cVec4&, const D3DXMATRIX&, int, float))(shared::base + 0x9E5C30))(this, out, WorldPos, matrix, __unused, farZ);
	}

	void calculateProjectionMatrix()
	{
		((void(__thiscall *)(cCameraViewProj*))(shared::base + 0x9E5AA0))(this);
	}
};

VALIDATE_SIZE(cCameraViewProj, 0x2C0);
