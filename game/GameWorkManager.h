#pragma once

#include <shared.h>

class GameWorkManager
{
public:

    virtual ~GameWorkManager() {};

    BOOL startup()
    {
        return ReturnCallVMTFunc<BOOL, 1, GameWorkManager *>(this);
    }

    void shutdown()
    {
        CallVMTFunc<2, GameWorkManager *>(this);
    }

    void tick(float deltaTime)
    {
        CallVMTFunc<3, GameWorkManager *>(this);
    }

    int startBattle(char* a2, int a3)
    {
        return ReturnCallVMTFunc<int, 4, GameWorkManager*, char*, int>(this, a2, a3);
    }

    void gameOverEvent()
    {
        CallVMTFunc<7, GameWorkManager *>(this);
    }

    BOOL isInBattle()
    {
        return ReturnCallVMTFunc<BOOL, 9, GameWorkManager *>(this);
    }

    void processTakeDamage()
    {
        CallVMTFunc<10, GameWorkManager *>(this);
    }

    void takeDamage()
    {
        CallVMTFunc<11, GameWorkManager*>(this);
    }

    void increaseCombo()
    {
        CallVMTFunc<13, GameWorkManager*>(this);
    }

    void increasePartsCut()
    {
        CallVMTFunc<14, GameWorkManager *>(this);
    }

    void receiveBP(int bp)
    {
        CallVMTFunc<15, GameWorkManager*>(this);
    }

    void increaseAlerts()
    {
        CallVMTFunc<20, GameWorkManager*>(this);
    }

    void increaseTauntCount()
    {
        CallVMTFunc<21, GameWorkManager *>(this);
    }

    int getCombo()
    {
        return ReturnCallVMTFunc<int, 29, GameWorkManager*>(this);
    }

    int getPartsCut()
    {
        return ReturnCallVMTFunc<int, 30, GameWorkManager *>(this);
    }

    int getKills()
    {
        return ReturnCallVMTFunc<int, 31, GameWorkManager *>(this);
    } 

    BOOL shouldShowComboDisp()
    {
        return ReturnCallVMTFunc<BOOL, 32, GameWorkManager *>(this);
    }

    int getAlerts()
    {
        return ReturnCallVMTFunc<int, 36, GameWorkManager *>(this);
    }

    void clearDisp()
    {
        CallVMTFunc<44, GameWorkManager *>(this);
    }
};