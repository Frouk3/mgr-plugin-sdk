#pragma once

#include <BehaviorEmBase.h>

class EmBaseDLC : public BehaviorEmBase
{ 
public:
    int field_DC0;
    int field_DC4;
    int field_DC8;
    int field_DCC;
    cEspControler m_RageEsp;
    int m_bWasRaged;
    float m_fRageDuration;
    int field_E88;

    EmBaseDLC()
    {
        ((void(__thiscall *)(EmBaseDLC *))(shared::base + 0x6A73F0))(this);
    }

    void SetRaged(void *a2 = nullptr)
    {
        CallVMTFunc<220, EmBaseDLC *, void *>(this, a2); 
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9C3C);
};

VALIDATE_SIZE(EmBaseDLC, 0xE8C);