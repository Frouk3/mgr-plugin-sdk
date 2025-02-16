#pragma once

#include <BehaviorPartsModel.h>

class cRayLeftHand : public BehaviorPartsModel
{
public:
    
    cRayLeftHand()
    {
        ((void(__thiscall *)(cRayLeftHand*))(shared::base + 0x6AE370))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9CCC);
};

VALIDATE_SIZE(cRayLeftHand, 0xA60);