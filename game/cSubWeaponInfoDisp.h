#pragma once

#include <cCustomObjCtrlManagerEx.h>
#include <cUISystem.h>

class cSubWeaponInfoDisp
{
public:
    int field_4;

    virtual ~cSubWeaponInfoDisp() {};
};

class cSubWeaponInfoDispParts : public cCustomObjCtrlManagerEx
{
public:

};

class cSubWeaponInfoDispBase : public cCustomObjWorkBase{};