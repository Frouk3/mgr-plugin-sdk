#pragma once

#include <Behavior.h>

// physical object

class BehaviorAppBase : public Behavior
{
public:
    int m_nHealth;
    int m_nMaxHealth;
    int field_878;
    int field_87C;
    int field_880;
    int field_884;
    int field_888;
    int field_88C;
    cVec4 m_vecVelocity;
    int field_8A0;
    float field_8A4;
    float field_8A8;
    int field_8AC;
    int field_8B0;
    int m_nAnimationFrame;
    int field_8B8;
    int field_8BC;
    int field_8C0;
    int field_8C4;
    int field_8C8;
    int field_8CC;
    int field_8D0;
    int field_8D4;
    float field_8D8;
    float field_8DC;
    cVec4 field_8E0;
    cVec4 field_8F0;
    cVec4 field_900;
    float m_fEntityTickRate;
    int field_914;
    Animation* m_pAnimation;
    EntityHandle m_QTETargetExecutor;
    float field_920;
    float field_924;
    float field_928;
    float field_92C;
    float field_930;
    float field_934;
    float field_938;
    int field_93C;
    int field_940;
    int field_944;
    int field_948;
    int field_94C;
    int field_950;
    int field_954;
    int field_958;
    int field_95C;
    cVec4 field_960;
    int field_970;
    float field_974;
    int field_978;
    int field_97C;
    float field_980;
    float field_984;
    float field_988;
    float field_98C;
    float field_990;
    float field_994;
    float field_998;
    float field_99C;
    float field_9A0;
    float field_9A4;
    float field_9A8;
    float field_9AC;
    float field_9B0;
    float field_9B4;
    float field_9B8;
    float field_9BC;
    float field_9C0;
    float field_9C4;
    float field_9C8;
    float field_9CC;
    int field_9D0;
    int field_9D4;
    int field_9D8;
    int field_9DC;
    float field_9E0;
    float field_9E4;
    float field_9E8;
    float field_9EC;
    float m_fYawDifference;
    int field_9F4;
    int field_9F8;
    int field_9FC;

    BehaviorAppBase()
    {
        ((void(__thiscall *)(BehaviorAppBase *))(shared::base + 0xEC370))(this);
    }

    // vft start
    
    void adjustHeading(float adjustment, float yawThreshold, float maxYaw, float desiredYawOffset)
    {
        CallVMTFunc<194, BehaviorAppBase *, float, float, float, float>(this, adjustment, yawThreshold, maxYaw, desiredYawOffset);
    }

    void damage(int damage, bool leave1Hp)
    {
        CallVMTFunc<195, BehaviorAppBase *, int, bool>(this, damage, leave1Hp);
    }

    void heal(int heal)
    {
        CallVMTFunc<196, BehaviorAppBase *, int>(this, heal);
    }

    void updateVelocity()
    {
        CallVMTFunc<199, BehaviorAppBase *>(this);
    }

    BOOL updateGroundVelocity(float deltaTime)
    {
        return ReturnCallVMTFunc<BOOL, 200, BehaviorAppBase *, float>(this, deltaTime);
    }

    // vft end

    void setupHealth(int health)
    {
        ((void(__thiscall *)(BehaviorAppBase *, int))(shared::base + 0x68EDF0))(this, health);
    }

    void setHealth(int health)
    {
        ((void (__thiscall *)(BehaviorAppBase *, int))(shared::base + 0x68EE20))(this, health);
    }

    int getHealth()
    {
        return ((int (__thiscall *)(BehaviorAppBase *))(shared::base + 0x68EEA0))(this);
    }

    static inline ContextInstance& ms_Context = *(ContextInstance*)(shared::base + 0x17E9C24);
};

VALIDATE_SIZE(BehaviorAppBase, 0xA00);