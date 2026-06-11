#pragma once

#include <CharacterProxyListener.h>
#include <lib.h>
#include <Hw.h>
#include <hkpAllCdPointCollector.h>
#include <hkpCharacterRigidBodyListener.h>
#include <CharacterProxy.h>

class CharacterControlPointCollector : public hkpAllCdPointCollector{};

class CharacterControlPointCollectorEm0111 : public hkpAllCdPointCollector{};

class CharacterRigidBodyListener : public hkpCharacterRigidBodyListener{};

class Behavior;

struct CharacterControl
{
    CharacterProxy* m_CharacterProxy;
    CharacterProxyListener* m_CharacterProxyListener;
    int field_8;
    int field_C;
    int m_OnGroundState;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    float field_40;
    int field_44;
    int field_48;
    int field_4C;
    lib::StaticArray<CharacterControl *, 8> m_AddonCharacters;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    Hw::cVec4 field_90;
    Hw::cVec4 field_A0;
    Hw::cVec4 field_B0;
    Hw::cVec4 field_C0;
    Hw::cVec4* m_pVelocity;
    int field_D4;
    int field_D8;
    int field_DC;
    Hw::cVec4 field_E0;
    Behavior* m_pOwner;
    float field_F4;
    float m_Height;
    float m_Radius;
    int field_100;
    int field_104;
    int field_108;
    int field_10C;
    int field_110;
    int field_114;
    int field_118;
    int field_11C;
    int field_120;
    CharacterControl* field_124;
    int field_128;
    hkpAllCdPointCollector* m_CdPointCollector;
    int field_130;
    int field_134;
    int field_138;
    int field_13C;
    Hw::cVec3 field_140;
    int field_14C;
    int field_150;
    int field_154;
    int field_158;
    int field_15C;
    int field_160;
    int field_164;
    int field_168;
    int field_16C;
    float field_170;
    int field_174;
    int field_178;
    int field_17C;
    Hw::cVec4 field_180;
    float field_190;
    float field_194;
    float field_198;
    float field_19C;
    Hw::cVec4 field_1A0;
    Hw::cVec4 field_1B0;
    int field_1C0;
    int field_1C4;
    int field_1C8;
    int field_1CC;
    int field_1D0;
    int field_1D4;
    int field_1D8;
    int field_1DC;

    bool isOnGround()
    {
        return MAKE_CALL(shared::base + 0x4E2740, bool(__thiscall*)(CharacterControl*), this);
    }

    void switchCollisionDetection(BOOL bEnabled)
    {
        MAKE_CALL(shared::base + 0x4E6C60, void(__thiscall*)(CharacterControl*, BOOL), this, bEnabled);
    }

    void setPosition(const Hw::cVec4& position, BOOL bResetVelocity)
    {
        MAKE_CALL(shared::base + 0x4E4580, void(__thiscall*)(CharacterControl*, const Hw::cVec4&, BOOL), this, position, bResetVelocity);
    }

    void toggleFalling(BOOL bEnable)
    {
        MAKE_CALL(shared::base + 0x4E0AF0, void(__thiscall*)(CharacterControl*, BOOL), this, bEnable);
    }
};