#pragma once

#include <BehaviorPartsModel.h>

class cRayArmor : public BehaviorPartsModel
{
public:

    cRayArmor()
    {
        MAKE_CALL(shared::base + 0x6B6BA0, void(__thiscall *)(cRayArmor *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x17E9CD8);
};

VALIDATE_SIZE(cRayArmor, 0xA60);