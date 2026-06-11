#pragma once

#include <cXmlBinary.h>
#include <shared.h>
#include <Slot.h>
#include <lib.h>

class cPhaseAbstract
{
private:
    int _pad04[2];
public:
    lib::StaticArray<int, 64> m_ContentsId;

    cPhaseAbstract() { MAKE_CALL(shared::base + 0x9664B0, void(__thiscall *)(cPhaseAbstract*), this); }

    void startup() { MAKE_VCALL(2, void(__thiscall *)(cPhaseAbstract*), this); }
    void update() { MAKE_VCALL(3, void(__thiscall *)(cPhaseAbstract*), this); }
    void cleanup() { MAKE_VCALL(4, void(__thiscall *)(cPhaseAbstract*), this); }
    void onFlagPhase(int a2, const char *subPhase, int a4) { MAKE_VCALL(5, void(__thiscall *)(cPhaseAbstract *, int, const char *, int), this, a2, subPhase, a4); }
    void onSave() { MAKE_VCALL(6, void(__thiscall *)(cPhaseAbstract*), this); }
    void offFlagPhase(int a2, const char *subPhase) { MAKE_VCALL(7, void(__thiscall *)(cPhaseAbstract *, int, const char *), this, a2, subPhase); }

    virtual ~cPhaseAbstract() {};
};

class SubPhaseSlot : public Slot
{
public:
    int field_4;
};

struct PhaseManager
{
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    unsigned int m_NowPhase;
    unsigned int m_NowSubPhaseHash;
    char m_pNowSubPhase[16];
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
    int field_BC;
    int field_C0;
    int field_C4;
    int field_C8;
    int field_CC;
    int field_D0;
    int field_D4;
    int field_D8;
    int field_DC;
    int field_E0;
    int field_E4;
    int field_E8;
    int field_EC;
    int field_F0;
    int field_F4;
    int field_F8;
    int field_FC;
    int field_100;
    int field_104;
    int field_108;
    int field_10C;
    int field_110;
    int field_114;
    int field_118;
    int field_11C;
    int field_120;
    int field_124;
    int field_128;
    int field_12C;
    int field_130;
    int field_134;
    int field_138;
    float field_13C;
    float field_140;
    float field_144;
    float field_148;
    int field_14C;
    int field_150;
    int field_154;
    int field_158;
    int field_15C;
    int field_160;
    int field_164;
    int field_168;
    int field_16C;
    int field_170;
    int field_174;
    int field_178;
    int field_17C;
    int field_180;
    int field_184;
    int field_188;
    int field_18C;
    float field_190;
    float field_194;
    float field_198;
    float field_19C;
    int field_1A0;
    int field_1A4;
    int field_1A8;
    int field_1AC;
    int field_1B0;
    int field_1B4;
    cXmlBinary field_1B8;
    cXmlBinary field_1D8;
    int field_1F8;
    int field_1FC;
    int field_200;
    int field_204;
    int field_208;
    int field_20C;
    int field_210;
    int field_214;
    int field_218;
    int field_21C;
    float field_220;
    float field_224;
    float field_228;
    float field_22C;
    int field_230;
    int field_234;
    int field_238;
    int field_23C;
    int field_240;
    int field_244;
    int field_248;
    int field_24C;
    int field_250;
    int field_254;
    int field_258;
    int field_25C;
    int field_260;

    /* // perhaps named differently and not in the PhaseManager class
    static inline int getCurrentSubPhase() 
    {
        return MAKE_CALL(shared::base + 0x532720, int (__cdecl *)());
    }
    */
    int createReadRoomList(int a2, int a3, int a4)
    {
        return MAKE_CALL(shared::base + 0x945560, int (__thiscall *)(PhaseManager *, int, int, int), this, a2, a3, a4);
    }
    bool isCurrentPhase(const char *phase)
    {
        return MAKE_CALL(shared::base + 0x945560, bool (__thiscall *)(PhaseManager *, const char *), this, phase);
    }
    bool isDLCPhase()
    {
        return MAKE_CALL(shared::base + 0x9466F0, bool (__thiscall *)(PhaseManager *), this);
    }
    bool isSamDLC()
    {
        return MAKE_CALL(shared::base + 0x946780, bool (__thiscall *)(PhaseManager *), this);
    }
    bool isWolfDLC()
    {
        return MAKE_CALL(shared::base + 0x9467A0, bool (__thiscall *)(PhaseManager *), this);
    }
    int setDefaultData()
    {
        return MAKE_CALL(shared::base + 0x94E890, int (__thiscall *)(PhaseManager *), this);
    }
    bool isPassSubPhase(int a2, bool a3, const char *debugLog)
    {
        return MAKE_CALL(shared::base + 0x94F0B0, bool (__thiscall *)(PhaseManager *, int, bool , const char*), this, a2, a3, debugLog);
    }
    void startup()
    {
        MAKE_CALL(shared::base + 0x958370, void (__thiscall *)(PhaseManager *), this);
    }
    bool setSubPhaseData(const char* phase)
    {
        return MAKE_CALL(shared::base + 0x958D70, bool (__thiscall *)(PhaseManager *, const char *), this, phase);
    }
    bool setPhaseData(int a2)
    {
        return MAKE_CALL(shared::base + 0x95ED60, bool (__thiscall *)(PhaseManager*, int), this, a2);
    }
    void gameOverEvent(int a2)
    {
        MAKE_CALL(shared::base + 0x9664E0, void (__thiscall *)(PhaseManager *, int), this, a2);
    }
    void requestSubPhaseChange(const char* phase, BOOL checkIfPass, int a3)
    {
        MAKE_CALL(shared::base + 0x95EA40, void (__thiscall *)(PhaseManager*, const char*, BOOL, int), this, phase, checkIfPass, a3);
    }
    void requestPhaseChange(int phase, const char* subPhase)
    {
        MAKE_CALL(shared::base + 0x95E850, void (__thiscall *)(PhaseManager*, int, const char*), this, phase, subPhase);
    }
};

static inline PhaseManager& g_PhaseManager = *(PhaseManager*)(shared::base + 0x14B9140);