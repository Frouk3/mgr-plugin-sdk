#pragma once

#include <cUISystem.h>

struct cDamageDisp
{
    cUIWorkBase *field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;

    virtual ~cDamageDisp() {};
};

class cDamageDispBase : public cUIWorkBase{};

class cDamageDispPrologueBase : public cUIWorkBase
{
public:
    int field_1F0;
    int field_1F4;
    int field_1F8;
    int field_1FC;
};