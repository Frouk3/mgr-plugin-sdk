#pragma once

#include <cCameraViewProj.h>
#include <D3dx9math.h>
#include <EntityHandle.h>
#include <cCameraFrustum.h>

class Pl0000;

class cCamera : public cCameraViewProj, public cCameraFrustum
{
public:

    cCamera() { ((void(__thiscall *)(cCamera *))(shared::base + 0x8406F0))(this); }
    void startup() {((void(__thiscall *)(cCamera *))(shared::base + 0x9A8390))(this); }
    void update() { ((void(__thiscall *)(cCamera *))(shared::base + 0x9A8480))(this); }
};

VALIDATE_SIZE(cCamera, 0x360);
