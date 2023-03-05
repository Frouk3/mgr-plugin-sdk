#pragma once
#include "Hw.h"

class cCameraViewProj : public Hw::CameraProj, public Hw::cCameraBase
{
public:
    virtual ~cCameraViewProj() override {};
};
