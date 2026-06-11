#pragma once

#include <cCameraViewProj.h>
#include <D3dx9math.h>
#include <EntityHandle.h>
#include <cCameraFrustum.h>

class Pl0000;

class cCamera : public cCameraViewProj, public cCameraFrustum
{
public:

    cCamera() { MAKE_CALL(shared::base + 0x8406F0, void(__thiscall *)(cCamera*), this); }
    void startup() { MAKE_CALL(shared::base + 0x9A8390, void(__thiscall *)(cCamera*), this); }
    void update() { MAKE_CALL(shared::base + 0x9A8480, void(__thiscall *)(cCamera*), this); }
};

VALIDATE_SIZE(cCamera, 0x360);
