#pragma once

#include "cObj.h"
#include "hkpRigidBody.h"
#include "cLockonPartsList.h"
#include "BattleParameterImplement.h"
#include "EspCtrlCustomImpl.h"
#include "CharacterControl.h"
#include "lib.h"
#include "StateMachineContextPl0010.h"
#include "StateMachineFactoryPl0010.h"
#include <D3dx9math.h>
#include <AnimationMapManagerImplement.h>
#include "Collision.h"
#include "RigidBodyCollision.h"

struct ClothSimulation
{
    struct ClothWork
    {
        int field_0;
        int field_4;
        int field_8;
        int field_C;
        int field_10;
        int field_14;
        int field_18;
        float field_1C;
        float field_20;
        float field_24;
        float field_28;
        float field_2C;
        float field_30;
        float field_34;
        float field_38;
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
        float field_E0;
        float field_E4;
        float field_E8;
        int field_EC;
        int field_F0;
        int field_F4;
        int field_F8;
        float field_FC;
    };

    struct Physics
    {
        int m_nNum;
        float m_fLimitSpringRate;
        float m_fSpdRate;
        float m_fStretchy;
        unsigned __int16 m_nBundleNum;
        unsigned __int16 m_nBundleNum2;
        float m_fThick;
        cVec3 m_vecGravity;
        int m_nGravityPartsNo;
        float m_fFirstBundleRate;
        cVec3 m_vecWind;
        int m_nWindPartsNo;
        cVec3 m_vecWindOffset;
        float m_fWindSin;
        float m_fHitAdjustRate;
        float m_fOriginalRate;
        int m_nParentGravity;
        int m_nFixAxis;
        int m_bNoStretchy;
        int m_bWorldWindEnable;
        int m_bAtCenter;
        int m_bLateAddMode;
        float m_fExpandMax;

        struct PhysPart
        {
            unsigned __int16 m_nNo;
            unsigned __int16 m_nNoDown;
            unsigned __int16 m_nNoPoly;
            unsigned __int16 m_nNoFix;
            float m_fRotLimit;
            float field_C;
            cVec3 m_vecOffset;
            float m_fOriginalRate;
        };
    };

    int field_0;
    float field_4;
    float field_8;
    float field_C;
    int field_10;
    float field_14;
    int field_18;
    ClothSimulation::ClothWork* field_1C;
    float field_20;
    int field_24;
    float field_28;
    float field_2C;
    float field_30;
    float field_34;
    int field_38;
    float field_3C;
    float field_40;
    float field_44;
    float field_48;
    float field_4C;
    float field_50;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    float field_6C;
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
    int field_13C;
    int field_140;
    int field_144;
    int field_148;
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
    int field_190;
    int field_194;
    int field_198;
    int field_19C;
    int field_1A0;
    int field_1A4;
    int field_1A8;
    int field_1AC;
    int field_1B0;
    int field_1B4;
    int field_1B8;
    int field_1BC;
    int field_1C0;
    int field_1C4;
    int field_1C8;
    int field_1CC;
    int field_1D0;
    int field_1D4;
    int field_1D8;
    int field_1DC;
    int field_1E0;
    int field_1E4;
    int field_1E8;
    int field_1EC;
    int field_1F0;
    int field_1F4;
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
    int field_220;
    int field_224;
    int field_228;
    int field_22C;
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
    int field_264;
    int field_268;
    int field_26C;
    int field_270;
    int field_274;
    int field_278;
    int field_27C;
    int field_280;
    int field_284;
    int field_288;
    int field_28C;
    int field_290;
    int field_294;
    int field_298;
    int field_29C;
    int field_2A0;
    int field_2A4;
    int field_2A8;
    int field_2AC;
    int field_2B0;
    int field_2B4;
    int field_2B8;
    int field_2BC;
    int field_2C0;
    int field_2C4;
    int field_2C8;
    int field_2CC;
    int field_2D0;
    int field_2D4;
    int field_2D8;
    int field_2DC;
    int field_2E0;
    int field_2E4;
    int field_2E8;
    int field_2EC;
    int field_2F0;
    int field_2F4;
    int field_2F8;
    int field_2FC;
    int field_300;
    int field_304;
    int field_308;
    int field_30C;
    int field_310;
    int field_314;
    int field_318;
    int field_31C;
    int field_320;
    int field_324;
    int field_328;
    int field_32C;
    int field_330;
    int field_334;
    int field_338;
    int field_33C;
    int field_340;
    int field_344;
    int field_348;
    int field_34C;
    int field_350;
    int field_354;
    int field_358;
    int field_35C;
    int field_360;
    int field_364;
    int field_368;
    int field_36C;
    int field_370;
    int field_374;
    int field_378;
    int field_37C;
    int field_380;
    int field_384;
    int field_388;
    int field_38C;
    int field_390;
    int field_394;
    int field_398;
    int field_39C;
    int field_3A0;
    int field_3A4;
    int field_3A8;
    int field_3AC;
    int field_3B0;
    int field_3B4;
    int field_3B8;
    int field_3BC;
    int field_3C0;
    int field_3C4;
    int field_3C8;
    int field_3CC;
    int field_3D0;
    int field_3D4;
    int field_3D8;
    int field_3DC;
    int field_3E0;
    int field_3E4;
    int field_3E8;
    int field_3EC;
    int field_3F0;
    int field_3F4;
    int field_3F8;
    int field_3FC;
    int field_400;
    int field_404;
    int field_408;
    int field_40C;
    int field_410;
    int field_414;
    int field_418;
    int field_41C;
    int field_420;
    int field_424;
    int field_428;
    int field_42C;
    int field_430;
    int field_434;
    int field_438;
    int field_43C;
    int field_440;
    int field_444;
    int field_448;
    int field_44C;
    int field_450;
    int field_454;
    int field_458;
    int field_45C;
    int field_460;
    int field_464;
    int field_468;
    int field_46C;
    int field_470;
    int field_474;
    int field_478;
    int field_47C;
    int field_480;
    int field_484;
    int field_488;
    int field_48C;
    int field_490;
    int field_494;
    int field_498;
    int field_49C;
    int field_4A0;
    int field_4A4;
    int field_4A8;
    int field_4AC;
    int field_4B0;
    int field_4B4;
    int field_4B8;
    int field_4BC;
    int field_4C0;
    int field_4C4;
    int field_4C8;
    int field_4CC;
    int field_4D0;
    int field_4D4;
    int field_4D8;
    int field_4DC;
    int field_4E0;
    int field_4E4;
    int field_4E8;
    int field_4EC;
    int field_4F0;
    int field_4F4;
    int field_4F8;
    int field_4FC;
    int field_500;
    int field_504;
    int field_508;
    int field_50C;
    int field_510;
    int field_514;
    int field_518;
    int field_51C;
    int field_520;
    int field_524;
    int field_528;
    int field_52C;
    int field_530;
    int field_534;
    int field_538;
    int field_53C;
    int field_540;
    int field_544;
    int field_548;
    int field_54C;
    int field_550;
    int field_554;
    int field_558;
    int field_55C;
    int field_560;
    int field_564;
    int field_568;
    int field_56C;
    int field_570;
    int field_574;
    int field_578;
    int field_57C;
    int field_580;
    int field_584;
    int field_588;
    int field_58C;
    int field_590;
    int field_594;
    int field_598;
    int field_59C;
    int field_5A0;
    int field_5A4;
    int field_5A8;
    int field_5AC;
    int field_5B0;
    int field_5B4;
    int field_5B8;
    int field_5BC;
    int field_5C0;
    int field_5C4;
    int field_5C8;
    int field_5CC;
    int field_5D0;
    int field_5D4;
    int field_5D8;
    int field_5DC;
    int field_5E0;
    int field_5E4;
    int field_5E8;
    int field_5EC;
    int field_5F0;
    int field_5F4;
    int field_5F8;
    int field_5FC;
    int field_600;
    int field_604;
    int field_608;
    int field_60C;
    int field_610;
    int field_614;
    int field_618;
    int field_61C;
    int field_620;
    int field_624;
    int field_628;
    int field_62C;
    int field_630;
    int field_634;
    int field_638;
    int field_63C;
    int field_640;
    int field_644;
    int field_648;
    int field_64C;
    int field_650;
    int field_654;
    int field_658;
    int field_65C;
    int field_660;
    int field_664;
    int field_668;
    int field_66C;
    int field_670;
    int field_674;
    int field_678;
    int field_67C;
    int field_680;
    int field_684;
    int field_688;
    int field_68C;
    int field_690;
    int field_694;
    int field_698;
    int field_69C;
    int field_6A0;
    int field_6A4;
    int field_6A8;
    int field_6AC;
    int field_6B0;
    int field_6B4;
    int field_6B8;
    int field_6BC;
    int field_6C0;
    int field_6C4;
    int field_6C8;
    int field_6CC;
    int field_6D0;
    int field_6D4;
    int field_6D8;
    int field_6DC;
    int field_6E0;
    int field_6E4;
    int field_6E8;
    int field_6EC;
    int field_6F0;
    int field_6F4;
    int field_6F8;
    int field_6FC;
    int field_700;
    int field_704;
    int field_708;
    int field_70C;
    int field_710;
    int field_714;
    int field_718;
    int field_71C;
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
    int field_750;
    int field_754;
    int field_758;
    int field_75C;
    int field_760;
    int field_764;
    int field_768;
    int field_76C;
    int field_770;
    int field_774;
    int field_778;
    int field_77C;
    int field_780;
    int field_784;
    int field_788;
    int field_78C;
    int field_790;
    int field_794;
    int field_798;
    int field_79C;
    int field_7A0;
    int field_7A4;
    int field_7A8;
    int field_7AC;
    int field_7B0;
    int field_7B4;
    int field_7B8;
    int field_7BC;
    int field_7C0;
    int field_7C4;
    int field_7C8;
    int field_7CC;
    int field_7D0;
    int field_7D4;
    int field_7D8;
    int field_7DC;
    int field_7E0;
    int field_7E4;
    int field_7E8;
    int field_7EC;
    int field_7F0;
    int field_7F4;
    int field_7F8;
    int field_7FC;
    int field_800;
    int field_804;
    int field_808;
    int field_80C;
    int field_810;
    int field_814;
    int field_818;
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
    int field_87C;
    int field_880;
    int field_884;
    int field_888;
    int field_88C;
    int field_890;
    int field_894;
    int field_898;
    int field_89C;
    int field_8A0;
    int field_8A4;
    int field_8A8;
    int field_8AC;
    int field_8B0;
    int field_8B4;
    int field_8B8;
    int field_8BC;
    int field_8C0;
    int field_8C4;
    int field_8C8;
    int field_8CC;
    int field_8D0;
    int field_8D4;
    int field_8D8;
    int field_8DC;
    int field_8E0;
    int field_8E4;
    int field_8E8;
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
    int field_924;
    int field_928;
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
    int field_960;
    int field_964;
    int field_968;
    int field_96C;
    int field_970;
    int field_974;
    int field_978;
    int field_97C;
    int field_980;
    int field_984;
    int field_988;
    int field_98C;
    int field_990;
    int field_994;
    int field_998;
    int field_99C;
    int field_9A0;
    int field_9A4;
    int field_9A8;
    int field_9AC;
    int field_9B0;
    int field_9B4;
    int field_9B8;
    int field_9BC;
    int field_9C0;
    int field_9C4;
    int field_9C8;
    int field_9CC;
    int field_9D0;
    int field_9D4;
    int field_9D8;
    int field_9DC;
    int field_9E0;
    int field_9E4;
    int field_9E8;
    int field_9EC;
    int field_9F0;
    int field_9F4;
    int field_9F8;
    int field_9FC;
    int field_A00;
    int field_A04;
    int field_A08;
    int field_A0C;
    int field_A10;
    int field_A14;
    int field_A18;
    int field_A1C;
    int field_A20;
    int field_A24;
    int field_A28;
    int field_A2C;
    int field_A30;
    int field_A34;
    int field_A38;
    int field_A3C;
    int field_A40;
    int field_A44;
    int field_A48;
    int field_A4C;
    int field_A50;
    int field_A54;
    int field_A58;
    int field_A5C;
    int field_A60;
    int field_A64;
    int field_A68;
    int field_A6C;
    int field_A70;
    int field_A74;
    int field_A78;
    int field_A7C;
    int field_A80;
    int field_A84;
    int field_A88;
    int field_A8C;
    int field_A90;
    int field_A94;
    int field_A98;
    int field_A9C;
    int field_AA0;
    int field_AA4;
    int field_AA8;
    int field_AAC;
    int field_AB0;
    int field_AB4;
    int field_AB8;
    int field_ABC;
    int field_AC0;
    int field_AC4;
    int field_AC8;
    int field_ACC;
    int field_AD0;
    int field_AD4;
    int field_AD8;
    int field_ADC;
    int field_AE0;
    int field_AE4;
    int field_AE8;
    int field_AEC;
    int field_AF0;
    int field_AF4;
    int field_AF8;
    int field_AFC;
    int field_B00;
    float m_fLimitSpringRate;
    float m_fSpdRate;
    float m_fStretchy;
    unsigned short m_nBundleNum;
    short m_nBundleNum2;
    int field_B14;
    float m_fThick;
    int field_B1C;
    int field_B20;
    int field_B24;
    int field_B28;
    int field_B2C;
    cVec4 m_vecGravity;
    int m_nGravityPartsNo;
    float m_fFirstBundleRate;
    int field_B48;
    int field_B4C;
    cVec4 m_vecWind;
    int m_nWindPartsNo;
    int field_B64;
    int field_B68;
    int field_B6C;
    cVec4 m_vecWindOffset;
    float m_fWindSin;
    float m_fHitAdjustRate;
    float field_B88;
    float field_B8C;
    float field_B90;
    float m_fOriginalRate;
    int field_B98;
    int field_B9C;
    float m_fExpandMax;
    int field_BA4;
    int field_BA8;
    int field_BAC;
    int m_bNoStretchy;
    int m_bWorldWindEnable;
    int m_bAtCenter;
    int m_bLateAddmode;
    float field_BC0;
    int field_BC4;
    int field_BC8;
    int m_nFixAxis;
    int m_nParentGravity;
    int field_BD4;
    int field_BD8;
    int field_BDC;
};

struct Constraints
{
    int m_nIndex;
    EntityHandle m_nMainEntity;
    EntityHandle m_nObjectEntityHandle;
    unsigned int m_nBone;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    Hw::cVec4 m_vecRotation;
    Hw::cVec4 m_vecOffset;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
};

class Behavior : public cObj
{
public:
    struct AnimationSlot
    {
        int field_0;
        int field_4;
        char m_AnimName[16];
        Behavior* m_Parent;
        int field_1C;
        AnimationMap::Unit* m_AnimationMap;
        int field_24;
        float m_fAnimTimer;
        int field_2C;
    };

    struct EffectIntegrationContainer
    {
        int field_0;
        int field_4;
        int field_8;
        int field_C;
        int field_10;
        int field_14;
        int field_18;
    };

    struct InstructionContainer
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
    };

    int field_530;
    int field_534;
    int field_538;
    int field_53C;
    cVec4 field_540;
    int field_550;
    int field_554;
    int field_558;
    int field_55C;
    float field_560;
    float field_564;
    float field_568;
    float field_56C;
    float field_570;
    float field_574;
    float field_578;
    float field_57C;
    float field_580;
    float field_584;
    float field_588;
    int field_58C;
    char field_590;
    int field_594;
    int field_598;
    int field_59C;
    int field_5A0;
    int field_5A4;
    int field_5A8;
    int field_5AC;
    int field_5B0;
    int field_5B4;
    int field_5B8;
    int field_5BC;
    int field_5C0;
    int field_5C4;
    int field_5C8;
    int field_5CC;
    int field_5D0;
    int field_5D4;
    int field_5D8;
    int field_5DC;
    int field_5E0;
    int field_5E4;
    int field_5E8;
    int field_5EC;
    hkpRigidBody* field_5F0;
    hkpRigidBody* field_5F4;
    int field_5F8;
    int field_5FC;
    float field_600;
    int field_604;
    int field_608;
    int m_pBehaviorInfo;
    int field_610;
    int field_614;
    unsigned int m_nCurrentAction;
    int m_nCurrentActionId;
    int field_620;
    int field_624;
    int m_nPreviousAction;
    int m_nPreviousActionId;
    int field_630;
    int field_634;
    Hw::CriticalSection* field_638;
    lib::AllocatedArray<InstructionContainer>* m_pInstructionContainerArray;
    int field_640;
    int field_644;
    int field_648;
    int field_64C;
    int field_650;
    int field_654;
    int field_658;
    int field_65C;
    int field_660;
    int field_664;
    int field_668;
    EntityHandle field_66C;
    int field_670;
    int field_674;
    Hw::cFixedVector<int> field_678;
    int field_68C;
    int field_690;
    float field_694;
    float field_698;
    float field_69C;
    float field_6A0;
    float field_6A4;
    float field_6A8;
    float field_6AC;
    char field_6B0;
    int field_6B4;
    int field_6B8;
    int field_6BC;
    int field_6C0;
    int field_6C4;
    int field_6C8;
    int field_6CC;
    float field_6D0;
    float field_6D4;
    float field_6D8;
    float field_6DC;
    int field_6E0;
    int field_6E4;
    float field_6E8;
    int field_6EC;
    cLockonPartsList m_cLockonPartsList;
    int field_710;
    int field_714;
    int field_718;
    int field_71C;
    int field_720;
    int field_724;
    int field_728;
    int field_72C;
    int field_730;
    int field_734;
    float field_738;
    int field_73C;
    int field_740;
    int field_744;
    int field_748;
    int field_74C;
    int field_750;
    BattleParameterImplement* m_pBattleParameterImplement;
    int field_758;
    lib::AllocatedArray<AnimationMap::Unit>** m_ppAnimationUnit;
    int field_760;
    CharacterControl* m_pCharacterControl;
    int field_768;
    ClothSimulation* m_pCloth;
    int field_770;
    lib::StaticArray<AnimationSlot, 16>* m_pAnimationSlot;
    int field_778;
    int field_77C;
    int field_780;
    float field_784;
    int field_788;
    int field_78C;
    int field_790;
    int field_794;
    EspCtrlCustomImpl* m_pEspCtrlCustomImpl;
    cEspControler* field_79C;
    lib::StaticArray<EffectIntegrationContainer, 32>* m_pEffectIntegrationContainer;
    lib::StaticArray<Collision *, 250> *m_pAttackCollision;
    lib::StaticArray<Collision *, 64> *m_pDefenseCollisions;
    int field_7AC;
    RigidBodyCollision* m_pRigidBodyCollision;
    void* m_pRigidBodyList;
    lib::AllocatedArray<Collision *>* m_pAllocatedCollisionArray;
    int field_7BC;
    float field_7C0;
    lib::StaticArray<Constraints, 32>** m_ppContraints;
    int field_7C8;
    int field_7CC;
    StateMachineContextPl0010* m_pStateMachineContext;
    StateMachineFactoryPl0010* m_pStateMachineFactory;
    int field_7D8;
    int field_7DC;
    int field_7E0;
    int field_7E4;
    int field_7E8;
    int field_7EC;
    int field_7F0;
    int field_7F4;
    int field_7F8;
    int field_7FC;
    int field_800;
    int field_804;
    int field_808;
    int field_80C;
    int field_810;
    int field_814;
    int field_818;
    int field_81C;
    int field_820;
    __int16 field_824;
    int field_828;
    int field_82C;
    int field_830;
    int field_834;
    int field_838;
    int field_83C;
    int field_840;
    int field_844;
    char field_848;
    char field_849;
    int field_84C;
    int field_850;
    int field_854;
    int field_858;
    int field_85C;
    float field_860;
    float field_864;
    float field_868;
    float field_86C;

    Behavior()
    {
        ((void(__thiscall *)(Behavior *))(shared::base + 0x6A3540))(this);
    }

// vft

    BOOL startup()
    {
        return ReturnCallVMTFunc<BOOL, 16, Behavior *>(this);
    }

    BOOL shutdown()
    {
        return ReturnCallVMTFunc<BOOL, 17, Behavior *>(this);
    }

    void updateLogic()
    {
        CallVMTFunc<18, Behavior*>(this);
    }

    void tick()
    {
        CallVMTFunc<19, Behavior *>(this);
    }

    void updateModel()
    {
        CallVMTFunc<20, Behavior *>(this);
    }
    
    void updateEntity()
    {
        CallVMTFunc<21, Behavior*>(this);
    }

    Hw::cVec4 *getTransPos()
    {
        return ReturnCallVMTFunc<Hw::cVec4 *, 26, Behavior *>(this);
    }

    void setTransPos(const Hw::cVec4& transPos)
    {
        CallVMTFunc<27, Behavior *, const Hw::cVec4&>(this, transPos);
    }

    void offsetTransPos(const Hw::cVec4& offset)
    {
        CallVMTFunc<28, Behavior *, const Hw::cVec4&>(this, offset);
    }

    void changeHeight(const float height)
    {
        CallVMTFunc<29, Behavior *, float>(this, height);
    }

    void place(const Hw::cVec4 &pos, const Hw::cVec4& rotation, const Hw::cVec4& size)
    {
        CallVMTFunc<30, Behavior *, const Hw::cVec4&, const Hw::cVec4&, const Hw::cVec4&>(this, pos, rotation, size);
    }

    void place(const Hw::cVec4 &pos, const Hw::cVec4 &rotation)
    {
        CallVMTFunc<31, Behavior *, const Hw::cVec4&, const Hw::cVec4&>(this, pos, rotation);
    }

    Hw::cVec4* getRotation()
    {
        return ReturnCallVMTFunc<Hw::cVec4*, 33, Behavior *>(this);
    }

    void setRotation(const Hw::cVec4& rotation)
    {
        CallVMTFunc<34, Behavior *, const Hw::cVec4&>(this, rotation);
    }

    Hw::cVec4* getSize()
    {
        return ReturnCallVMTFunc<Hw::cVec4*, 35, Behavior *>(this);
    }

    void setSize(const Hw::cVec4& size)
    {
        CallVMTFunc<36, Behavior *, const Hw::cVec4&>(this, size);
    }

    int getSequence()
    {
        return ReturnCallVMTFunc<int, 37, Behavior *>(this);
    }

    int getIndex()
    {
        return ReturnCallVMTFunc<int, 38, Behavior *>(this);
    }

    int getSequenceFile(const char *a2)
    {
        return ReturnCallVMTFunc<int, 39, Behavior *, const char*>(this, a2);
    }

    void transform(D3DXMATRIX *matrix)
    {
        CallVMTFunc<45, Behavior *, D3DXMATRIX *>(this, matrix);
    }

    void inverse(D3DXMATRIX *matrix)
    {
        CallVMTFunc<46, Behavior *, D3DXMATRIX *>(this, matrix);
    }

    void setStealthCamoEnabled(bool bEnable)
    {
        CallVMTFunc<68, Behavior *, bool>(this, bEnable);
    }

    void setSeqAtk()
    {
        CallVMTFunc<74, Behavior *>(this);
    }

    void *setCutCreateInfo()
    {
        return ReturnCallVMTFunc<void *, 110, Behavior *>(this);
    }

    bool isAlive()
    {
        return ReturnCallVMTFunc<bool, 128, Behavior *>(this);
    }

    Hw::cVec4 getOffsetPosition()
    {
        return ReturnCallVMTFunc<Hw::cVec4, 159, Behavior *>(this);
    }

    void forceDie()
    {
        CallVMTFunc<190, Behavior*>(this);
    }

// vft end

    void setState(int action, int actId, int a3, int a4)
    {
        ((void (__thiscall *)(Behavior *, int, int, int, int))(shared::base + 0x68CAF0))(this, action, actId, a3, a4);
    }

    int getCurrentActionId()
    {
        return ((int (__thiscall *)(Behavior *))(shared::base + 0x68CAC0))(this);
    }

    int getCurrentAction()
    {
        return ((int (__thiscall *)(Behavior *))(shared::base + 0x68CAB0))(this);
    }

    bool setupCloth(int a2)
    {
        return ((bool (__thiscall *)(Behavior *, int))(shared::base + 0x692380))(this, a2);
    }

    int requestAnimationByMap(int animId, Entity* pEntityFrom, int a4, float fInterpolation, float a6, unsigned int nFlags, float fStartFrame, float a9)
    {
        return ((int (__thiscall *)(Behavior *, int, Entity *, int, float, float, unsigned int, float, float))(shared::base + 0x6A4520))(this, animId, pEntityFrom, a4, fInterpolation, a6, nFlags, fStartFrame, a9);
    }

    int requestAnimationByMap(Entity *pAnimEntity, int a2, int a3, int a4, int a5, int a6, const char* motId, float a9, unsigned int nFlags)
    {
        return ((int (__thiscall *)(Behavior *, Entity *, int, int, int, int, int, const char*, float, unsigned int))(shared::base + 0x694850))(this, pAnimEntity, a2, a3, a4, a5, a6, motId, a9, nFlags);
    }

    void removeConstraint(int constraintId)
    {
        ((void (__thiscall *)(Behavior*, int))(shared::base + 0x69E060))(this, constraintId);
    }

    void attachObject(int constrId, Entity* entityAttachTo, Entity* attachedEntity, int bone, int _bone)
    {
        ((void(__thiscall*)(Behavior*, int, Entity*, Entity*, int, int))(shared::base + 0x68C5F0))(this, constrId, entityAttachTo, attachedEntity, bone, _bone);
    }

    void shutdownBattleParameter()
    {
        ((void(__thiscall*)(Behavior*))(shared::base + 0x692A00))(this);
    }

    Animation* getAnimation()
    {
        return ((Animation * (__thiscall*)(Behavior*))(shared::base + 0x692F90))(this);
    }

    float getSpeedRate()
    {
        return ((float(__thiscall*)(Behavior*))(shared::base + 0x692FF0))(this);
    }

    float getDelta()
    {
        return ((float(__thiscall*)(Behavior*))(shared::base + 0x693060))(this);
    }

    Constraints* getConstraints(int id)
    {
        return ((Constraints * (__thiscall*)(Behavior*, int))(shared::base + 0x6943E0))(this, id);
    }

    Entity* getConstraintsEntity(int id)
    {
        return ((Entity * (__thiscall*)(Behavior*, int))(shared::base + 0x694480))(this, id);
    }

    void shutdownConstraints()
    {
        ((void(__thiscall*)(Behavior*))(shared::base + 0x6944D0))(this);
    }

    void setConstraintsBone(int id, unsigned int bone, unsigned int _bone)
    {
        ((void(__thiscall*)(Behavior*, int, unsigned int, unsigned int))(shared::base + 0x69E120))(this, id, bone, _bone);
    }

    int setDirectAnimation(void* mot, void* seq, int a4, float fInterpolation, float a6, unsigned int nFlags, float fStartFrame, float a9)
    {
       return ((int(__thiscall*)(Behavior*, void*, void*, int, float, float, unsigned int, float, float))(shared::base + 0x69EFB0))(this, mot, seq, a4, fInterpolation, a6, nFlags, fStartFrame, a9);
    }

    // Takes all values from the animation map and plays the animation
    int requestAnimationByMap(int id)
    {
        return ((int(__thiscall*)(Behavior*, int))(shared::base + 0x6A3F60))(this, id);
    }
    
    // Unlike others, motion file is taken from the data file of this object
    int rqeuestAnimationByName(const char* anim, int a3, float fInterpolation, int a5, unsigned int nFlags, float fStartFrame, float a8)
    {
        return ((int(__thiscall*)(Behavior*, const char*, int, float, int, unsigned int, float, float))(shared::base + 0x69E290))(this, anim, a3, fInterpolation, a5, nFlags, fStartFrame, a8);
    }

    static inline ContextInstance &Context = *(ContextInstance*)(shared::base + 0x17E9C20);
};

struct BehaviorData
{

};

VALIDATE_SIZE(Behavior::AnimationSlot, 0x30);
VALIDATE_SIZE(Behavior, 0x870);