#pragma once

#include <cUISystem.h>

class cAttentionDisp
{
public:
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;

    virtual ~cAttentionDisp() {};
};

class cAttentionDispBase : public cCustomObjWorkBase{};