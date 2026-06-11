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
		MAKE_VCALL(1, void(__thiscall *)(cCameraViewProj*), this);
	}

	// Maybe those methods down below are actually from Hw::CameraProj?

	void screenToWorld(Hw::cVec4& out, const Hw::cVec4& ScreenPos, const Hw::cMtx &viewMatrix, int __unused) 
	{
		MAKE_CALL(shared::base + 0x9E4E40, void(__thiscall *)(cCameraViewProj*, Hw::cVec4&, const Hw::cVec4&, const Hw::cMtx&, int), this, out, ScreenPos, viewMatrix, __unused);
	}

	void screenToWorld(Hw::cVec4& out, const Hw::cVec4& ScreenPos, const Hw::cMtx &viewMatrix)
	{
		MAKE_CALL(shared::base + 0x9E4DC0, void(__thiscall *)(cCameraViewProj*, Hw::cVec4&, const Hw::cVec4&, const Hw::cMtx&), this, out, ScreenPos, viewMatrix);
	}

	BOOL worldToScreen(Hw::cVec4& out, const Hw::cVec4& WorldPos, const Hw::cMtx& matrix, float farZ)
	{
		return MAKE_CALL(shared::base + 0x9E5B60, BOOL(__thiscall *)(cCameraViewProj*, Hw::cVec4&, const Hw::cVec4&, const Hw::cMtx&, float), this, out, WorldPos, matrix, farZ);
	}

	BOOL worldToScreen(Hw::cVec4& out, const Hw::cVec4& WorldPos, const Hw::cMtx& matrix, int __unused, float farZ)
	{
		return MAKE_CALL(shared::base + 0x9E5C30, BOOL(__thiscall *)(cCameraViewProj*, Hw::cVec4&, const Hw::cVec4&, const Hw::cMtx&, int, float), this, out, WorldPos, matrix, __unused, farZ);
	}

	void updateViewProjMatrixPers() { MAKE_CALL(shared::base + 0x9A3940, void(__thiscall *)(cCameraViewProj*), this); }
};

VALIDATE_SIZE(cCameraViewProj, 0x2C0);
