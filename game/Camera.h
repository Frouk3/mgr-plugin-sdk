#pragma once
#include "BehaviorEmBase.h"
#include "D3DXMATRIX.h"

namespace Camera
{
    namespace Math
    {

    };
    class StateAnimation;
    class StateBattle;
    class StateBattleFixed;
    class StateNode;
    class StateNodeTrait;
    class StatePerpetrator;
    class StateGallery;
    class StateDiveKill;
    class StateSlashingTarget;
    class StateSubWeaponAiming;
};

class Camera::StateNode
{
public:

    virtual void Function0() {};
    virtual ~StateNode() {};
};

class Camera::StateNodeTrait
{
public:

    virtual ~StateNodeTrait() {};
};

class Camera::StateBattle : public Camera::StateNode
{
public:
    int field_4;
    int field_8;
    int field_C;
    BehaviorEmBase *m_pLockedEnemy;
    float field_14;
    float field_18;
    int field_1C;
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    float field_30;
    int field_34;
    int field_38;
    float field_3C;
    float field_40;

    virtual ~StateBattle() override {};
};

class Camera::StatePerpetrator : public Camera::StateNode
{
public:
    int field_4;
    int field_8;
    int field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    int field_6C;
    float field_70;
    float field_74;
    float field_78;
    float field_7C;

    virtual ~StatePerpetrator() override {};
};

class Camera::StateBattleFixed : public Camera::StateNode
{
public:
    int field_4;
    int field_8;
    int field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    cVec4 field_30;
    cVec4 field_40;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    cVec4 field_60;
    cVec4 field_70;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    float field_94;
    int field_98;
    int field_9C;

    virtual ~StateBattleFixed() override {};
};

class Camera::StateGallery : public Camera::StateNode
{
public:
    int field_4;
    int field_8;
    int field_C;
    cVec4 field_10;
    cVec4 field_20;

    virtual ~StateGallery() override {};
};

class Camera::StateDiveKill : public Camera::StateNode
{
public:
    int field_4;
    int field_8;
    int field_C;
    cVec4 field_10;
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
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
    float field_80;
    int field_84;
    int field_88;
    int field_8C;
    cVec4 field_90;
    cVec4 field_A0;
    float field_B0;
    float field_B4;
    float field_B8;
    float field_BC;
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
    float field_F0;
    int field_F4;
    int field_F8;
    int field_FC;

    virtual ~StateDiveKill() override {};
};

class Camera::StateSlashingTarget : public Camera::StateNode
{
public:
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    int field_14;
    int field_18;
    int field_1C;
    D3DXMATRIX field_20;
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;

    virtual ~StateSlashingTarget() override {};
};

class Camera::StateSubWeaponAiming : public Camera::StateNode
{
public:
    int field_4;
    int field_8;
    int field_C;
    float field_10;
    float field_14;
    float field_18;
    int field_1C;
    float field_20;
    float field_24;
    float field_28;
    int field_2C;

    virtual ~StateSubWeaponAiming() override {};
};

class Camera::StateAnimation : public Camera::StateNode
{
public:
    
    virtual ~StateAnimation() override {};
};