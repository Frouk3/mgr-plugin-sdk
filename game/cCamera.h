#pragma once

#include <cCameraViewProj.h>
#include <D3dx9math.h>
#include <EntityHandle.h>
#include <cCameraFrustum.h>

class Pl0000;

class cCamera : public cCameraViewProj, public cCameraFrustum
{
public:

    void initialize()
    {
        CallVMTFunc<1, cCamera *>(this);
    }

    void setProjectionMatrix(const D3DXMATRIX& matrix, int a3)
    {
        ((void(__thiscall *)(cCamera *, const D3DXMATRIX&, int))(shared::base + 0x9E5B30))(this, matrix, a3);
    }
};

VALIDATE_SIZE(cCamera, 0x360);
