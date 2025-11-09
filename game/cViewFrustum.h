#pragma once

#include <Hw.h>

class __declspec(align(16)) cViewFrustum
{
    Hw::cVec4 m_planes[5];
    Hw::cVec4 m_Trans;
    float m_Aspect;
    float m_CosX;
    float m_SinX;
    float m_CosY;
    float m_SinY;
    float m_NearZ;
    float m_FarZ;

    void initialize(float fovy, float nearZ, float farZ, unsigned int width, unsigned int height) { ((void(__thiscall *)(cViewFrustum*, float, float, float, unsigned int, unsigned int))(shared::base + 0x9E5560))(this, fovy, nearZ, farZ, width, height); }
    void set(const Hw::cVec4& trans, const Hw::cVec4& target, const Hw::cVec4& up) { ((void(__thiscall *)(cViewFrustum*, const Hw::cVec4&, const Hw::cVec4&, const Hw::cVec4&))(shared::base + 0x9E6460))(this, trans, target, up);}
    void setFovy(float fovy) { ((void(__thiscall *)(cViewFrustum*, float))(shared::base + 0x9E59F0))(this, fovy); }
};

VALIDATE_SIZE(cViewFrustum, 0x80);