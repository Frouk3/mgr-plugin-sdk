#pragma once

#include <cCustomObjCtrlManager.h>

class cTitleStart : public cCustomObjCtrlManager
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
    Hw::cTexture field_40[4];
    int field_B0;
    int field_B4;
    float field_B8;
    float field_BC;
    int field_C0;
    int field_C4;
    int m_bUseController; // perhaps PC input rather than controller
};