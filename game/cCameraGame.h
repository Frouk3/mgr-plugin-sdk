#pragma once
#include <cCameraApp.h>
#include <BehaviorEmBase.h>
#include <BehaviorCamera.h>

class cCameraGame : public cCameraApp
{
public:
    float field_6E0;
    void* m_pStates;
    int field_6E8;
    int field_6EC;
    struct LockonSystem
    {
        int m_nLockType;
        EntityHandle m_TargetEntity;
        Behavior *m_Target;
        int m_nBone;
        cVec4 field_10;
        cVec4 m_vecPosition;
    } m_LockonSystem;
    int field_720;
    int field_724;
    int field_728;
    int field_72C;
    int field_730;
    int field_734;
    int field_738;
    int field_73C;
    int field_740;
    int field_744;
    int field_748;
    int field_74C;
    float field_750;
    float field_754;
    float field_758;
    int field_75C;
    float field_760;
    int field_764;
    int field_768;
    float field_76C;
    int field_770;
    float field_774;
    float field_778;
    float field_77C;
    float field_780;
    float field_784;
    float field_788;
    float field_78C;
    float field_790;
    float field_794;
    float field_798;
    int field_79C;
    float field_7A0;
    float field_7A4;
    int field_7A8;
    int field_7AC;
    float field_7B0;
    float field_7B4;
    int field_7B8;
    int field_7BC;
    float field_7C0;
    float field_7C4;
    float field_7C8;
    int field_7CC;
    int field_7D0;
    int field_7D4;
    float field_7D8;
    float field_7DC;
    float field_7E0;
    float field_7E4;
    float field_7E8;
    float field_7EC;
    float field_7F0;
    float field_7F4;
    int field_7F8;
    float field_7FC;
    float field_800;
    float field_804;
    float field_808;
    int field_80C;
    int field_810;
    float field_814;
    float field_818;
    int field_81C;
    int field_820;
    int field_824;
    int field_828;
    int field_82C;
    int field_830;
    int field_834;
    int field_838;
    int field_83C;
    int field_840;
    int field_844;
    int field_848;
    int field_84C;
    int field_850;
    int field_854;
    int field_858;
    int field_85C;
    int field_860;
    int field_864;
    int field_868;
    int field_86C;
    int field_870;
    int field_874;
    int field_878;
    float field_87C;
    float field_880;
    float field_884;
    float field_888;
    float field_88C;
    int field_890;
    int field_894;
    int field_898;
    int field_89C;
    int field_8A0;
    int field_8A4;
    int field_8A8;
    float field_8AC;
    float field_8B0;
    int m_nCameraType;
    int field_8B8;
    float field_8BC;
    float field_8C0;
    float field_8C4;
    int field_8C8;
    int field_8CC;
    float field_8D0;
    float field_8D4;
    float field_8D8;
    float field_8DC;
    float field_8E0;
    float field_8E4;
    float field_8E8;
    int field_8EC;
    int field_8F0;
    int field_8F4;
    int field_8F8;
    int field_8FC;
    int field_900;
    int field_904;
    int field_908;
    int field_90C;
    int field_910;
    int field_914;
    int field_918;
    int field_91C;
    int field_920;
    float field_924;
    float field_928;
    int field_92C;
    int field_930;
    int field_934;
    int field_938;
    int field_93C;
    int field_940;
    int field_944;
    int field_948;
    int field_94C;
    int field_950;
    int field_954;
    int field_958;
    int field_95C;
    cCamera m_Cameras[4];
    Entity* m_pCameraObjectEnt;
    BehaviorCamera* m_pCameraObject;
    int field_16E8;
    int field_16EC;
    cCameraGame* field_16F0;
    int field_16F4;
    float field_16F8;
    int field_16FC;
    int field_1700;
    float field_1704;
    int field_1708;
    int field_170C;

    static inline cCameraGame& Instance = *(cCameraGame*)(shared::base + 0x17EA1D0);
    
    // screenPos - Vector of screen position
    // screenPos.z - How far away it from the screen rect
    // screenPos.w - Distance between given worldPos position and camera position
    BOOL worldToScreen(cVec4 &screenPos, const cVec4 &worldPos)
    {
        return ((BOOL(__thiscall*)(cCameraGame*, cVec4&, const cVec4&))(shared::base + 0x99FA80))(this, screenPos, worldPos);
    }

    void screenToWorld(cVec4& worldPos, const cVec4& screenPos)
    {
        ((void(__thiscall*)(cCameraGame*, cVec4&, const cVec4&))(shared::base + 0x99FAB0))(this, worldPos, screenPos);
    }

    void safePositionTargetXz(const cVec4& pos, const cVec4& lookAt, const cVec4& offset, float fov)
    {
        ((void(__thiscall*)(cCameraGame*, const cVec4&, const cVec4&, const cVec4&, float))(shared::base + 0x9B8CB0))(this, pos, lookAt, offset, fov);
    }
    
    void updateView()
    {
        ((void(__thiscall*)(cCameraGame*))(shared::base + 0x9B8090))(this);
    }

    void setSmoothness(float smoothness)
    {
        ((void(__thiscall*)(cCameraGame*, float))(shared::base + 0x9A8810))(this, smoothness);
    }

    void setCameraType(int type)
    {
        ((void(__thiscall*)(cCameraGame*, int))(shared::base + 0x9C1300))(this, type);
    }
};