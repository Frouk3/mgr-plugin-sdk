#pragma once

#include <Behavior.h>

class Pl0110 : public Behavior
{
public:
    Entity *m_pVisor;
    Entity *m_pSheath;
    Entity *m_pHead;
    float field_87C;

    Pl0110()
    {
        ((void(__thiscall *)(Pl0110*))(shared::base + 0x6A6070))(this);
    }

    void setIdle()
    {
        ((void(__thiscall*)(Pl0110*))(shared::base + 0x1F0BA0))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x17353E8);
};

VALIDATE_SIZE(Pl0110, 0x880);