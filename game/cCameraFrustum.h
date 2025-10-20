#pragma once

#include <Hw.h>

class cViewFrustum
{
    cVec4 m_planes[6];
    float m_Aspect;
    float m_CosX;
    float m_SinX;
    float m_CosY;
    float m_SinY;
    float m_NearZ;
    float m_FarZ;

    void set(float fov, float nearClip, float farClip, int width, int height)
    {
        ((void(__thiscall *)(cViewFrustum*, float, float, float, int, int))(shared::base + 0x9E5560))(this, fov, nearClip, farClip, width, height);
    }

    void setFOV(float fov)
    {
        ((void(__thiscall *)(cViewFrustum*, float))(shared::base + 0x9E59F0))(this, fov);
    }
};

class cCameraFrustum
{
public:
    int field_4;
    int field_8;
    int field_C;
    cViewFrustum m_Vfrustum;
    int field_8C;
    int m_bUpdateFrustum;
    int field_94;
    int field_98;
    int field_9C;

    virtual ~cCameraFrustum() {};
};

VALIDATE_SIZE(cCameraFrustum, 0xA0);
VALIDATE_SIZE(cViewFrustum, 0x7C);