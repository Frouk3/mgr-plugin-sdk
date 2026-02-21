#pragma once

#include <cCameraViewProj.h>
#include <D3dx9math.h>
#include <EntityHandle.h>
#include <cCameraFrustum.h>

class Pl0000;

class cCamera : public cCameraViewProj, public cCameraFrustum
{
public:

    cCamera() { CallMethod<0x8406F0, cCamera *>(this); }
    void startup() { CallMethod<0x9A8390, cCamera *>(this); }
    void update() { CallMethod<0x9A8480, cCamera *>(this); }
};

VALIDATE_SIZE(cCamera, 0x360);
