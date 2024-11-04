#pragma once
#include "cCameraViewProj.h"
#include <D3dx9math.h>
#include "EntityHandle.h"
#include "cCameraFrustum.h"

class Pl0000;

class cCamera : public cCameraViewProj, public cCameraFrustum
{
public:


};

VALIDATE_SIZE(cCamera, 0x360);
