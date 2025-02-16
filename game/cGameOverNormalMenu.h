#pragma once

#include <cCustomObjCtrlManager.h>
#include <cMessWindowCtrl.h>

class cGameOverNormalMenu : public cCustomObjCtrlManager
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
    float field_40;
    cMessWindowCtrl field_44;
};

VALIDATE_SIZE(cGameOverNormalMenu, 0x54);