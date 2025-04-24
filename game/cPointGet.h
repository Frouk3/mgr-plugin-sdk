#pragma once

#include <cUISystem.h>
#include <cCustomObjCtrlManager.h>

class cPointGetParts : public cCustomObjCtrlManager 
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
    float field_44;
    float field_48;
    float field_4C;
};

class cPointGet
{
public:
    cPointGetParts *m_pPointGetParts;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;

    virtual ~cPointGet() {};
};