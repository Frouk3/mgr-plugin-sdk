#pragma once

#include "Behavior.h"
#include "EspControllerBullet.h"

class BehaviorBulletBase : public Behavior
{
public:
    int field_870;
    int field_874;
    int field_878;
    int field_87C;
    int field_880;
    int field_884;
    int field_888;
    int field_88C;
    int field_890;
    int field_894;
    int field_898;
    int field_89C;
    int field_8A0;
    int field_8A4;
    int field_8A8;
    int field_8AC;
    int field_8B0;
    int field_8B4;
    int field_8B8;
    int field_8BC;
    int field_8C0;
    int field_8C4;
    int field_8C8;
    int field_8CC;
    int field_8D0;
    int field_8D4;
    int field_8D8;
    int field_8DC;
    int field_8E0;
    int field_8E4;
    int field_8E8;
    int field_8EC;
    float field_8F0;
    float field_8F4;
    float field_8F8;
    int field_8FC;
    int field_900;
    int field_904;
    int field_908;
    int field_90C;
    cVec4 field_910;
    cVec4 field_920;
    int field_930;
    int field_934;
    int field_938;
    int field_93C;
    int field_940;
    int field_944;
    int field_948;
    int field_94C;
    int field_950;
    int field_954;
    int field_958;
    int field_95C;
    int field_960;
    int field_964;
    int field_968;
    int field_96C;
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
    int field_9A0;
    int field_9A4;
    int field_9A8;
    int field_9AC;
    int field_9B0;
    int field_9B4;
    int field_9B8;
    int field_9BC;
    int field_9C0;
    int field_9C4;
    int field_9C8;
    int field_9CC;
    int field_9D0;
    int field_9D4;
    int field_9D8;
    int field_9DC;
    int field_9E0;
    int field_9E4;
    int field_9E8;
    int field_9EC;
    int field_9F0;
    int field_9F4;
    int field_9F8;
    int field_9FC;
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
    int field_AC0;
    int field_AC4;
    int field_AC8;
    int field_ACC;
    int field_AD0;
    int field_AD4;
    int field_AD8;
    int field_ADC;
    int field_AE0;
    int field_AE4;
    int field_AE8;
    int field_AEC;
    int field_AF0;
    int field_AF4;
    int field_AF8;
    int field_AFC;
    int field_B00;
    int field_B04;
    int field_B08;
    int field_B0C;
    int field_B10;
    int field_B14;
    int field_B18;
    int field_B1C;
    int field_B20;
    int field_B24;
    int field_B28;
    int field_B2C;
    int field_B30;
    int field_B34;
    int field_B38;
    int field_B3C;
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
    float field_B80;
    float field_B84;
    float field_B88;
    float field_B8C;
    float field_B90;
    float field_B94;
    float field_B98;
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
    float field_BF0;
    int field_BF4;
    float field_BF8;
    float field_BFC;
    int field_C00;
    int field_C04;
    int field_C08;
    int field_C0C;
    float field_C10;
    float field_C14;
    float field_C18;
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
    int field_CD0;
    int field_CD4;
    int field_CD8;
    int field_CDC;
    int field_CE0;
    int field_CE4;
    int field_CE8;
    int field_CEC;
    int field_CF0;
    int field_CF4;
    int field_CF8;
    int field_CFC;
    int field_D00;
    int field_D04;
    int field_D08;
    int field_D0C;
    int field_D10;
    int field_D14;
    int field_D18;
    int field_D1C;
    int field_D20;
    int field_D24;
    int field_D28;
    int field_D2C;
    int field_D30;
    int field_D34;
    int field_D38;
    int field_D3C;
    int field_D40;
    int field_D44;
    int field_D48;
    int field_D4C;
    int field_D50;
    int field_D54;
    int field_D58;
    int field_D5C;
    int field_D60;
    int field_D64;
    int field_D68;
    int field_D6C;
    int field_D70;
    int field_D74;
    int field_D78;
    int field_D7C;
    float field_D80;
    int field_D84;
    int field_D88;
    int field_D8C;
    int field_D90;
    int field_D94;
    float field_D98;
    float field_D9C;
    float field_DA0;
    int field_DA4;
    int field_DA8;
    int field_DAC;
    cEspControler field_DB0;
    cEspControler field_E60;
    int field_F10;
    int field_F14;
    int field_F18;
    int field_F1C;
    float field_F20;
    int field_F24;
    int field_F28;
    float field_F2C;
    int field_F30;
    int field_F34;
    int field_F38;
    int field_F3C;
    int field_F40;
    int field_F44;
    int field_F48;
    int field_F4C;
    int field_F50;
    int field_F54;
    int field_F58;
    int field_F5C;
    int field_F60;
    int field_F64;
    int field_F68;
    int field_F6C;
    int field_F70;
    int field_F74;
    int field_F78;
    int field_F7C;
    int field_F80;
    int field_F84;
    int field_F88;
    int field_F8C;
    int field_F90;
    int field_F94;
    int field_F98;
    int field_F9C;
    int field_FA0;
    int field_FA4;
    int field_FA8;
    int field_FAC;
    int field_FB0;
    int field_FB4;
    int field_FB8;
    int field_FBC;
    int field_FC0;
    int field_FC4;
    int field_FC8;
    int field_FCC;
    int field_FD0;
    int field_FD4;
    int field_FD8;
    int field_FDC;
    int field_FE0;
    int field_FE4;
    int field_FE8;
    int field_FEC;
    int field_FF0;
    int field_FF4;
    int field_FF8;
    int field_FFC;
    int field_1000;
    int field_1004;
    int field_1008;
    int field_100C;
    int field_1010;
    int field_1014;
    int field_1018;
    int field_101C;
    int field_1020;
    int field_1024;
    int field_1028;
    int field_102C;
    int field_1030;
    int field_1034;
    int field_1038;
    int field_103C;
    int field_1040;
    int field_1044;
    int field_1048;
    int field_104C;
    int field_1050;
    int field_1054;
    int field_1058;
    int field_105C;
    int field_1060;
    int field_1064;
    int field_1068;
    int field_106C;
    int field_1070;
    int field_1074;
    int field_1078;
    int field_107C;
    int field_1080;
    int field_1084;
    int field_1088;
    int field_108C;
    int field_1090;
    int field_1094;
    int field_1098;
    int field_109C;
    int field_10A0;
    int field_10A4;
    int field_10A8;
    int field_10AC;
    int field_10B0;
    int field_10B4;
    int field_10B8;
    int field_10BC;
    int field_10C0;
    int field_10C4;
    int field_10C8;
    int field_10CC;
    int field_10D0;
    int field_10D4;
    int field_10D8;
    int field_10DC;
    int field_10E0;
    int field_10E4;
    int field_10E8;
    int field_10EC;
    int field_10F0;
    int field_10F4;
    int field_10F8;
    int field_10FC;
    int field_1100;
    int field_1104;
    float field_1108;
    int field_110C;
    int field_1110;
    int field_1114;
    int field_1118;
    int field_111C;
    int field_1120;
    int field_1124;
    int field_1128;
    int field_112C;
    EspControllerBullet field_1130;
    int field_1200;
    int field_1204;
    int field_1208;
    int field_120C;

    BehaviorBulletBase()
    {
        ((void (__thiscall *)(BehaviorBulletBase *))(shared::base + 0x6CCE00))(this);
    }
};

VALIDATE_SIZE(BehaviorBulletBase, 0x1210);