#pragma once

#include "BehaviorAppBase.h"

class BehaviorCamera : public BehaviorAppBase
{
public:
   int field_9F4;
    int field_9F8;
    int field_9FC;
    Animation *field_A00;
    EntityHandle field_A04;
    int field_A08;
    int field_A0C;
    int field_A10;
    float field_A14;
    int field_A18;
    int field_A1C;
    int field_A20;
    int field_A24;
    int field_A28;
    int field_A2C;
    int field_A30;
    int field_A34;
    int field_A38;
    int field_A3C;
    float field_A40;
    int field_A44;
    int field_A48;
    int field_A4C;
    float field_A50;
    EntityHandle field_A54;
    int field_A58;
    int field_A5C;

    BehaviorCamera()
    {
        ((void (__thiscall *)(BehaviorCamera *))(shared::base + 0x6AF350))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9C80);
};