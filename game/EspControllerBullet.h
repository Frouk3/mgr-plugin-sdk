#pragma once

#include <EspControllerHitStrip.h>

class EspControllerBullet : public EspControllerHitStrip
{
public:

    EspControllerBullet()
    {
        ((void (__thiscall *)(EspControllerBullet*))(shared::base + 0x5CF2E0))(this);
    }
};

VALIDATE_SIZE(EspControllerBullet, 0xD0);