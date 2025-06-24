#pragma once

#include <cCustomObjCtrlManager.h>

class cEventPauseMenu : public cCustomObjCtrlManager
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
};

VALIDATE_SIZE(cEventPauseMenu, 0x44);