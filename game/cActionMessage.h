#pragma once

#include <cActionMessageParts.h>

class cActionMessage
{
public:
    int field_4;
    int field_8;
    int field_C;
    cActionMessageParts *m_pActionMessageParts;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;

    virtual ~cActionMessage() {};
};