#pragma once
#include "cItemPossessionBase.h"

class cItemPossessionWeaponGun : public cItemPossessionBase
{
public:
    int m_nGunPossession;
    int m_nGunMaxPossession;
    int m_nGunDLCMaxPossession;
    int m_nAdditionPossession;
    int field_6C;
};