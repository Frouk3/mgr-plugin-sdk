#pragma once

#include <BehaviorPartsModel.h>

class cRayArmor : public BehaviorPartsModel
{
public:

    cRayArmor()
    {
        ((void(__thiscall *)(cRayArmor *))(shared::base + 0x6B6BA0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9CD8);
};

VALIDATE_SIZE(cRayArmor, 0xA60);