#pragma once

#include <Behavior.h>

class cScrObj : public Behavior
{
public:
    char m_ScrName[64];
    float field_8B0;
    float field_8B4;
    float field_8B8;
    float field_8BC;
    int field_8C0;
    int field_8C4;
    int field_8C8;
    int field_8CC;
    int field_8D0;
    int field_8D4;
    int field_8D8;
    int field_8DC;

    cScrObj()
    {
        ((void(__thiscall *)(cScrObj *))(shared::base + 0x6A6900))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x177B37C);
};

VALIDATE_SIZE(cScrObj, 0x8E0);