#pragma once

#include <BehaviorBm.h>

class Bm0304 : public BehaviorBm
{
public:
    int field_B40;
    int field_B44;
    int field_B48;
    int field_B4C;
    int field_B50;
    int field_B54;
    int field_B58;
    int field_B5C;
    int field_B60;
    int field_B64;
    int field_B68;
    int field_B6C;
    int field_B70;
    int field_B74;
    int field_B78;
    int field_B7C;
    int field_B80;
    int field_B84;
    int field_B88;
    int field_B8C;
    int field_B90;
    int field_B94;
    int field_B98;
    int field_B9C;
    int field_BA0;
    int field_BA4;
    int field_BA8;
    int field_BAC;
    int field_BB0;
    int field_BB4;
    int field_BB8;
    int field_BBC;
    int field_BC0;
    int field_BC4;
    int field_BC8;
    int field_BCC;
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
    int field_C60;
    int field_C64;
    int field_C68;
    int field_C6C;
    int field_C70;
    int field_C74;
    int field_C78;
    int field_C7C;
    int field_C80;
    int field_C84;
    int field_C88;
    int field_C8C;
    int field_C90;
    int field_C94;
    int field_C98;
    int field_C9C;
    int field_CA0;
    int field_CA4;
    int field_CA8;
    int field_CAC;
    int field_CB0;
    int field_CB4;
    int field_CB8;
    int field_CBC;
    int field_CC0;
    int field_CC4;
    int field_CC8;
    int field_CCC;

    Bm0304()
    {
        ((void(__thiscall *)(Bm0304 *))(shared::base + 0x6B03C0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x1734BD4);
};

VALIDATE_SIZE(Bm0304, 0xCD0);