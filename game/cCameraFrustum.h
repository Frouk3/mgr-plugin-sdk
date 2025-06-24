#pragma once

#include <Hw.h>

class cCameraFrustum
{
public:
    struct Frustum
    {
        cVec4 m_planes[6];
        float m_fAspectRatio;
        float m_fCosHalfFOVNorm;
        float m_fSinHalfFOVNorm;
        float m_fCosHalfFOV;
        float m_fSinHalfFOV;
        float m_fNearClip;
        float m_fFarClip;

        void set(float fov, float nearClip, float farClip, int width, int height)
        {
            ((void(__thiscall *)(Frustum*, float, float, float, int, int))(shared::base + 0x9E5560))(this, fov, nearClip, farClip, width, height);
        }

        void setFOV(float fov)
        {
            ((void(__thiscall *)(Frustum*, float))(shared::base + 0x9E59F0))(this, fov);
        }
    };

    int field_4;
    int field_8;
    int field_C;
    Frustum m_frustum;
    int field_8C;
    int m_bUpdateFrustum;
    int field_94;
    int field_98;
    int field_9C;

    virtual ~cCameraFrustum() {};
};

VALIDATE_SIZE(cCameraFrustum, 0xA0);
VALIDATE_SIZE(cCameraFrustum::Frustum, 0x7C);