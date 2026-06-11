#pragma once

#include <shared.h>

class GameWorkManager
{
public:

    virtual ~GameWorkManager() {};

    BOOL startup()
    {
        return MAKE_VCALL(1, BOOL(__thiscall*)(GameWorkManager*), this);
    }

    void shutdown()
    {
        MAKE_VCALL(2, void(__thiscall*)(GameWorkManager*), this);
    }

    void tick(float deltaTime)
    {
        MAKE_VCALL(3, void(__thiscall*)(GameWorkManager*, float), this, deltaTime);
    }

    int startBattle(char* a2, int a3)
    {
        return MAKE_VCALL(4, int(__thiscall*)(GameWorkManager*, char*, int), this, a2, a3);
    }

    void gameOverEvent()
    {
        MAKE_VCALL(7, void(__thiscall*)(GameWorkManager*), this);
    }

    BOOL isInBattle()
    {
        return MAKE_VCALL(9, BOOL(__thiscall*)(GameWorkManager*), this);
    }

    void processTakeDamage()
    {
        MAKE_VCALL(10, void(__thiscall*)(GameWorkManager*), this);
    }

    void takeDamage()
    {
        MAKE_VCALL(11, void(__thiscall*)(GameWorkManager*), this);
    }

    void increaseCombo()
    {
        MAKE_VCALL(13, void(__thiscall*)(GameWorkManager*), this);
    }

    void increasePartsCut()
    {
        MAKE_VCALL(14, void(__thiscall*)(GameWorkManager*), this);
    }

    void receiveBP(int bp)
    {
        MAKE_VCALL(15, void(__thiscall*)(GameWorkManager*, int), this, bp);
    }

    void increaseAlerts()
    {
        MAKE_VCALL(20, void(__thiscall*)(GameWorkManager*), this);
    }

    void increaseTauntCount()
    {
        MAKE_VCALL(21, void(__thiscall*)(GameWorkManager *), this);
    }

    int getCombo()
    {
        return MAKE_VCALL(29, int(__thiscall*)(GameWorkManager*), this);
    }

    int getPartsCut()
    {
        return MAKE_VCALL(30, int(__thiscall*)(GameWorkManager *), this);
    }

    int getKills()
    {
        return MAKE_VCALL(31, int(__thiscall*)(GameWorkManager *), this);
    }

    BOOL shouldShowComboDisp()
    {
        return MAKE_VCALL(32, BOOL(__thiscall*)(GameWorkManager *), this);
    }

    int getAlerts()
    {
        return MAKE_VCALL(36, int(__thiscall*)(GameWorkManager *), this);
    }

    void clearDisp()
    {
        MAKE_VCALL(44, void(__thiscall*)(GameWorkManager *), this);
    }
};