#pragma once

#include <BehaviorPartsModel.h>

class cRayLeftHand : public BehaviorPartsModel
{
public:
    
    cRayLeftHand()
    {
        MAKE_CALL(shared::base + 0x6AE370, void(__thiscall *)(cRayLeftHand*), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x17E9CCC);
};

VALIDATE_SIZE(cRayLeftHand, 0xA60);