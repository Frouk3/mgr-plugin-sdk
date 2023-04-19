#pragma once

#include "cCodecMenuParts.h"

class cCodecMenu
{
public:
    int field_4;
    int field_8;
    cCodecMenuParts* m_pcCodecMenuParts;

    virtual ~cCodecMenu() {};
};