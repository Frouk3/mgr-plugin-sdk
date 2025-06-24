#pragma once

#include <BehaviorAppBase.h>

class Em0312 : public BehaviorAppBase
{
public:
    int field_A00;
    int field_A04;
    int field_A08;
    int field_A0C;
    int field_A10;
    int field_A14;
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
    int field_A40;
    int field_A44;
    int field_A48;
    int field_A4C;
    int field_A50;
    int field_A54;
    int field_A58;
    int field_A5C;
    int field_A60;
    int field_A64;
    int field_A68;
    int field_A6C;
    int field_A70;
    int field_A74;
    int field_A78;
    int field_A7C;
    int field_A80;
    int field_A84;
    int field_A88;
    int field_A8C;
    int field_A90;
    int field_A94;
    int field_A98;
    int field_A9C;
    int field_AA0;
    int field_AA4;
    int field_AA8;
    int field_AAC;
    int field_AB0;
    int field_AB4;
    int field_AB8;
    int field_ABC;
    lib::StaticArray<Hw::cVec4, 16> field_AC0;
    int field_BD0;
    int field_BD4;
    int field_BD8;
    int field_BDC;
    int field_BE0;
    int field_BE4;
    int field_BE8;
    int field_BEC;
    int field_BF0;
    int field_BF4;
    int field_BF8;
    int field_BFC;
    int field_C00;
    int field_C04;
    int field_C08;
    int field_C0C;
    int field_C10;
    int field_C14;
    int field_C18;
    int field_C1C;
    int field_C20;
    int field_C24;
    int field_C28;
    int field_C2C;
    int field_C30;
    int field_C34;
    int field_C38;
    int field_C3C;
    int field_C40;
    int field_C44;
    int field_C48;
    int field_C4C;
    int field_C50;
    int field_C54;
    int field_C58;
    int field_C5C;

    Em0312()
    {
        ((void(__thiscall *)(Em0312 *))(shared::base + 0x6AD570))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x173516C);
};

VALIDATE_SIZE(Em0312, 0xC60);