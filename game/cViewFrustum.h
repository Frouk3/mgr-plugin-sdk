#pragma once

#include <Hw.h>

class cViewFrustum
{
public:
	Hw::cVec4 m_planes[5];
	Hw::cVec4 m_Trans;
	float m_Aspect;
	float m_CosX;
	float m_SinX;
	float m_CosY;
	float m_SinY;
	float m_NearZ;
	float m_FarZ;
private:
	int _pad7C;
public:

	void initialize(float fovy, float nearZ, float farZ, unsigned int width, unsigned int height) { CallMethod<0x9E5560, cViewFrustum*, float, float, float, unsigned int, unsigned int>(this, fovy, nearZ, farZ, width, height); }
	void set(const Hw::cVec4& trans, const Hw::cVec4& target, const Hw::cVec4& up) { CallMethod<0x9E6460, cViewFrustum*, const Hw::cVec4&, const Hw::cVec4&, const Hw::cVec4&>(this, trans, target, up); }
	void setFovy(float fovy) { CallMethod<0x9E59F0, cViewFrustum*, float>(this, fovy); }
};

VALIDATE_SIZE(cViewFrustum, 0x80);