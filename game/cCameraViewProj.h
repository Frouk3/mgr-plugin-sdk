#pragma once
#include <Hw.h>

class cCameraViewProj : public Hw::CameraProj, public Hw::cCameraBase
{
public:
	Hw::cMtx m_ViewProjMatrix;
	Hw::cMtx m_InverseViewProjMatrix;
	Hw::cMtx m_ViewProjMatrixOld;

	void initialize()
	{
		CallVMTFunc<1, cCameraViewProj*>(this);
	}

	// Maybe those methods down below are actually from Hw::CameraProj?

	void screenToWorld(Hw::cVec4& out, const Hw::cVec4& ScreenPos, const Hw::cMtx &viewMatrix, int __unused) 
	{
		((void(__thiscall *)(cCameraViewProj*, Hw::cVec4&, const Hw::cVec4&, const Hw::cMtx&, int))(shared::base + 0x9E4E40))(this, out, ScreenPos, viewMatrix, __unused);
	}

	void screenToWorld(Hw::cVec4& out, const Hw::cVec4& ScreenPos, const Hw::cMtx &viewMatrix)
	{
		((void(__thiscall *)(cCameraViewProj*, Hw::cVec4&, const Hw::cVec4&, const Hw::cMtx&))(shared::base + 0x9E4DC0))(this, out, ScreenPos, viewMatrix);
	}

	BOOL worldToScreen(Hw::cVec4& out, const Hw::cVec4& WorldPos, const Hw::cMtx& matrix, float farZ)
	{
		return ((BOOL(__thiscall *)(cCameraViewProj*, Hw::cVec4&, const Hw::cVec4&, const Hw::cMtx&, float))(shared::base + 0x9E5B60))(this, out, WorldPos, matrix, farZ);
	}

	BOOL worldToScreen(Hw::cVec4& out, const Hw::cVec4& WorldPos, const Hw::cMtx& matrix, int __unused, float farZ)
	{
		return ((BOOL(__thiscall *)(cCameraViewProj*, Hw::cVec4&, const Hw::cVec4&, const Hw::cMtx&, int, float))(shared::base + 0x9E5C30))(this, out, WorldPos, matrix, __unused, farZ);
	}

	void updateViewProjMatrixPers() { ((void(__thiscall *)(cCameraViewProj*))(shared::base + 0x9A3940))(this); }
};

VALIDATE_SIZE(cCameraViewProj, 0x2C0);
