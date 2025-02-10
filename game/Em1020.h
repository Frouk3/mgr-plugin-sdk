#pragma once

#include <BehaviorEmBase.h>

class Em1020 : public BehaviorEmBase
{
public:
    EntitySystem::SetInfo field_DC0;
    int field_ED8;
    int field_EDC;
    int field_EE0;
    int field_EE4;
    int field_EE8;
    int field_EEC;

    Em1020()
    {
        ((void(__thiscall *)(Em1020*))(shared::base + 0x6B09E0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17351E4);
};

VALIDATE_SIZE(Em1020, 0xEF0);