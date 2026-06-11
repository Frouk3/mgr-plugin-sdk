#pragma once

#include <Behavior.h>

class BehaviorLockOnMarker : public Behavior
{
public:
    cEspControler field_870;
    cEspControler field_920;
    int field_9D0;
    int field_9D4;
    int field_9D8;
    int field_9DC;

    BehaviorLockOnMarker()
    {
        MAKE_CALL(shared::base + 0x6A6670, void(__thiscall *)(BehaviorLockOnMarker *), this);
    }

    static inline ContextInstance& m_Context = *(ContextInstance*)(shared::base + 0x17E9CA4);
};

VALIDATE_SIZE(BehaviorLockOnMarker, 0x9E0);