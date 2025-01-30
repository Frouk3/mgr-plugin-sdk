#pragma once

#include <BehaviorDebrisBase.h>

class BehaviorDebrisObject : public BehaviorDebrisBase
{
public:
    int field_970;
    int field_974;
    int field_978;
    int field_97C;
    int field_980;
    int field_984;
    int field_988;
    int field_98C;
    int field_990;
    int field_994;
    int field_998;
    int field_99C;

    BehaviorDebrisObject()
    {
        ((void (__thiscall *)(BehaviorDebrisObject *))(shared::base + 0x1DA7D0))(this);
    }

    static inline ContextInstance &ms_Context = *(ContextInstance*)(shared::base + 0x1735308);
};

VALIDATE_SIZE(BehaviorDebrisObject, 0x9A0);