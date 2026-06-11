#pragma once

#include <Behavior.h>

/// This object doesn't emit any light unless it's material brightness is set to crazy values
/// Light changes simply through the meshes
/// Uses cnm00_SxXXX shader
/// This object also changes it's brightness from time to time automatically
class cLightVolumeObj : public Behavior
{
public:
    int field_870;
    int field_874;
    int field_878;
    int field_87C;

    cLightVolumeObj()
    {
        MAKE_CALL(shared::base + 0x6A6FA0, void(__thiscall *)(cLightVolumeObj *), this);
    }

    // There's no context for this object but from Behavior only
};

VALIDATE_SIZE(cLightVolumeObj, 0x880);