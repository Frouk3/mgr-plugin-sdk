#pragma once

#include <cCustomObjCtrlManager.h>
#include <cMessWindowCtrl.h>

class cGameOverHackingMenu : public cCustomObjCtrlManager
{
public:
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    float field_4C;
    int field_50;
    int field_54;
    cMessWindowCtrl field_58;
};

VALIDATE_SIZE(cGameOverHackingMenu, 0x68);