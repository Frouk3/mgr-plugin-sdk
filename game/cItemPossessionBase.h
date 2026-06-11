#pragma once

#include <cItemBase.h>

class cItemPossessionBase : public cItemBase
{
public:
    int m_nBasePossession;
    int m_nBaseMaxPossession;

    const char* getParent()
    {
        return MAKE_VCALL(4, const char*(__thiscall *)(cItemPossessionBase*), this);
    }

    int getMaxPossession()
    {
        return MAKE_VCALL(5, int(__thiscall *)(cItemPossessionBase*), this);
    }

    void receive(int Count)
    {
        MAKE_VCALL(6, void(__thiscall *)(cItemPossessionBase*, int), this, Count);
    }

    void receive()
    {
        MAKE_VCALL(7, void(__thiscall *)(cItemPossessionBase*), this);
    }

    void spend(int amount)
    {
        MAKE_VCALL(8, void(__thiscall *)(cItemPossessionBase*, int), this, amount);
    }

    void spend()
    {
        MAKE_VCALL(9, void(__thiscall *)(cItemPossessionBase*), this);
    }

    void set(int amount)
    {
        MAKE_VCALL(10, void(__thiscall *)(cItemPossessionBase*, int), this, amount);
    }

    BOOL hasFullPossession()
    {
        return MAKE_VCALL(11, BOOL(__thiscall *)(cItemPossessionBase*), this);
    }
    // duplicates at 13 & 14
    BOOL use()
    {
        return MAKE_VCALL(12, BOOL(__thiscall *)(cItemPossessionBase*), this);
    }

    BOOL _use()
    {
        return MAKE_VCALL(13, BOOL(__thiscall *)(cItemPossessionBase*), this);
    }

    BOOL __use()
    {
        return MAKE_VCALL(14, BOOL(__thiscall *)(cItemPossessionBase*), this);
    }

    BOOL hasPossession()
    {
        return MAKE_VCALL(15, BOOL(__thiscall *)(cItemPossessionBase*), this);
    }

    BOOL noUse()
    {
        return MAKE_VCALL(17, BOOL(__thiscall *)(cItemPossessionBase*), this);
    }

    int getEssentialPossession()
    {
        return MAKE_VCALL(18, int(__thiscall *)(cItemPossessionBase*), this);
    }

    int getPossession()
    {
        return MAKE_VCALL(19, int(__thiscall *)(cItemPossessionBase*), this);
    }

    int getMaxGunPossession()
    {
        return MAKE_VCALL(20, int(__thiscall *)(cItemPossessionBase*), this);
    }

    void receiveSilent(int amount)
    {
        MAKE_VCALL(21, void(__thiscall *)(cItemPossessionBase*, int), this, amount);
    }
};

VALIDATE_SIZE(cItemPossessionBase, 0x5C);