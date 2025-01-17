#pragma once

#include <cItemBase.h>

class cItemPossessionBase : public cItemBase
{
public:
    int m_nBasePossession;
    int m_nBaseMaxPossession;

    const char* getParent()
    {
        return ReturnCallVMTFunc<const char*, 4, cItemPossessionBase*>(this);
    }

    int getMaxPossession()
    {
        return ReturnCallVMTFunc<int, 5, cItemPossessionBase*>(this);
    }

    void receive(int Count)
    {
        CallVMTFunc<6, cItemPossessionBase*, int>(this, Count);
    }

    void receive()
    {
        CallVMTFunc<7, cItemPossessionBase*>(this);
    }

    void spend(int amount)
    {
        CallVMTFunc<8, cItemPossessionBase*, int>(this, amount);
    }

    void spend()
    {
        CallVMTFunc<9, cItemPossessionBase*>(this);
    }

    void set(int amount)
    {
        CallVMTFunc<10, cItemPossessionBase*, int>(this, amount);
    }

    BOOL hasFullPossession()
    {
        return ReturnCallVMTFunc<BOOL, 11, cItemPossessionBase*>(this);
    }
    // duplicates at 13 & 14
    BOOL use()
    {
        return ReturnCallVMTFunc<BOOL, 12, cItemPossessionBase*>(this);
    }

    BOOL _use()
    {
        return ReturnCallVMTFunc<BOOL, 13, cItemPossessionBase*>(this);
    }

    BOOL __use()
    {
        return ReturnCallVMTFunc<BOOL, 14, cItemPossessionBase*>(this);
    }

    BOOL hasPossession()
    {
        return ReturnCallVMTFunc<BOOL, 15, cItemPossessionBase*>(this);
    }

    BOOL noUse()
    {
        return ReturnCallVMTFunc<BOOL, 17, cItemPossessionBase*>(this);
    }

    int getEssentialPossession()
    {
        return ReturnCallVMTFunc<int, 18, cItemPossessionBase*>(this);
    }

    int getPossession()
    {
        return ReturnCallVMTFunc<int, 19, cItemPossessionBase*>(this);
    }

    int getMaxGunPossession()
    {
        return ReturnCallVMTFunc<int, 20, cItemPossessionBase*>(this);
    }

    void receiveSilent(int amount)
    {
        CallVMTFunc<21, cItemPossessionBase*, int>(this, amount);
    }
};

VALIDATE_SIZE(cItemPossessionBase, 0x5C);