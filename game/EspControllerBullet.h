#pragma once

#include <EspControllerHitStrip.h>

class EspControllerBullet : public EspControllerHitStrip
{
public:

    EspControllerBullet()
    {
        MAKE_CALL(shared::base + 0x5CF2E0, void(__thiscall *)(EspControllerBullet*), this);
    }
};

VALIDATE_SIZE(EspControllerBullet, 0xD0);