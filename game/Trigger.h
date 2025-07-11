#pragma once

#include <shared.h>
#include <Hw.h>
#include <lib.h>
#include <cFade.h>

namespace Trigger
{
    class cCondition;
    class cActionAbstract;

    class cCondPhaseJump;
    class cCondTrue;

    class cTriggerTask;

    inline struct gameFlags {
        unsigned int GAME_QTE_UI_DISABLE : 1;
        unsigned int GAME_MUGEN_ZANGEKI : 1;
        unsigned int GAME_OS_BOOT_MODE : 1;
        unsigned int GAME_PLAYER_ONESHOT_OFF : 1;
        unsigned int GAME_PLAYER_ONEHAND : 1;
        unsigned int GAME_RIPPERMODE_OFF : 1;
        unsigned int GAME_NAVI_UI_ON : 1;
        unsigned int GAME_PLAYER_NO_OVERHEAT : 1;

        unsigned int GAME_PLAYER_NO_DIE : 1;
        unsigned int GAME_SYSTEM_MAPAUTOLOAD_OFF : 1;
        unsigned int GAME_PLAYER_JUMP_OFF : 1;
        unsigned int GAME_PLAYER_DATSU_OFF : 1;
        unsigned int GAME_PLAYER_GECKO_TRAIL : 1;
        unsigned int GAME_PLAYER_GUARD_OFF : 1;
        unsigned int GAME_PLAYER_NINJYARUN_OFF : 1;
        unsigned int GAME_PLAYER_ZANGEKI_OFF : 1;

        unsigned int GAME_ACTIVE_B_PUSH : 1;
        unsigned int GAME_ACTIVE_Y_POUND : 1;
        unsigned int GAME_L1_ATTACK_OFF : 1;
        unsigned int GAME_IGNORE_PARKOUR_SLIDING : 1;
        unsigned int GAME_IGNORE_PARKOUR_WALL : 1;
        unsigned int GAME_IGNORE_PARKOUR_DOWNWARDCLIFF : 1;
        unsigned int GAME_IGNORE_PARKOUR_LOWOVER : 1;
        unsigned int GAME_PLAYER_ATTACK_OFF : 1;

        unsigned int GAME_PLAYER_WALK_ONLY : 1;
        unsigned int GAME_MISSILE_NINJYARUN_MODE : 1;
        unsigned int GAME_PLAYERBATTLEMOTIONEND_DEMO : 1;
        unsigned int GAME_PLAYERBATTLEEND_DEMO : 1;
        unsigned int GAME_AUTO_HPUP : 1;
        unsigned int GAME_ZANGEKIMODE : 1;
        unsigned int GAME_RECVCOMMU : 1;
        unsigned int GAME_FIRST_ENCOUNTER : 1;

        unsigned int GAME_TGS_MODE : 1;
        unsigned int GAME_XY_ATTACK_OFF : 1;
        unsigned int GAME_TUTORIAL_FROM_STORY : 1;
        unsigned int b35 : 1;
        unsigned int b36 : 1;
        unsigned int GAME_DISABLE_ZANGEKI : 1;
        unsigned int GAME_PLAYER_VISOR_ENABLED : 1;
        unsigned int GAME_RUNNING_X_ATTACK_OFF : 1;

        unsigned int b40 : 1;
        unsigned int b41 : 1;
        unsigned int GAME_PLAYER_NO_LOCKON_BUTTON : 1;
        unsigned int b43 : 1;
        unsigned int GAME_EM0091_MANUPILATE : 1;
        unsigned int b45 : 1;
        unsigned int GAME_HP1_RAIDEN : 1;
        unsigned int GAME_DEPRESSSION_RAIDEN : 1;

        unsigned int GAME_SOLDIER_MONOLOGUE : 1;
        unsigned int GAME_KOGEKKO_PLAY : 1;
        unsigned int GAME_WEAPON_SELECT : 1;
        unsigned int GAME_SLIDER_NINJARUN_MODE : 1;
        unsigned int GAME_CODEC_SUBJECTIVE_POINT_VIEW : 1;
        unsigned int GAME_INZANGEKI_CAMDIR : 1;
        unsigned int GAME_CAMERA_INVERSE_X : 1;
        unsigned int GAME_CAMERA_INVERSE_Y : 1;

        unsigned int GAME_NO_EXP_ADD : 1;
        unsigned int GAME_ITEM_NO_DROP : 1;
        unsigned int GAME_PHASE_END_UI_DISP_OFF : 1;
        unsigned int GAME_RESULT_DISP_ON : 1;
        unsigned int GAME_BATTLECOLLISION_OFF : 1;
        unsigned int GAME_PLAYER_NO_DIVEKILL : 1;
        unsigned int GAME_PLAYER_NO_MOVE : 1;
        unsigned int GAME_PLAYER_NO_XA : 1;
    } &GameFlags = *(Trigger::gameFlags*)(shared::base + 0x17EA090);

    inline struct stpFlags
    {
        unsigned int b1 : 1;
        unsigned int b2 : 1;
        unsigned int b3 : 1;
        unsigned int b4 : 1;
        unsigned int b5 : 1;
        unsigned int b6 : 1;
        unsigned int b7 : 1;
        unsigned int STP_KEY_INPUT : 1;

        unsigned int b9 : 1;
        unsigned int b10 : 1;
        unsigned int STP_MOUSE_UPDATE : 1;
        unsigned int STP_TRG_DELAY_PL_CHK : 1;
        unsigned int STP_SITUATION : 1;
        unsigned int STP_ENEMYSET : 1;
        unsigned int STP_SCENARIO : 1;
        unsigned int STP_EVENT_SKIP : 1;

        unsigned int STP_TRIGGER : 1;
        unsigned int STP_PL_CAM_KEY : 1;
        unsigned int STP_IK : 1;
        unsigned int STP_PL_ATTACK_KEY : 1;
        unsigned int STP_PL_MOVE_KEY : 1;
        unsigned int STP_PL_KEY : 1;
        unsigned int STP_SUBPL : 1;
        unsigned int STP_SHADOW : 1;

        unsigned int STP_FILTER : 1;
        unsigned int STP_UI : 1;
        unsigned int STP_SCR : 1;
        unsigned int STP_ESP : 1;
        unsigned int STP_ETCOBJ : 1;
        unsigned int STP_EM : 1;
        unsigned int STP_PL : 1;
        unsigned int STP_OBJ : 1;

        unsigned int b32 : 1;
        unsigned int b33 : 1;
        unsigned int b34 : 1;
        unsigned int b35 : 1;
        unsigned int b36 : 1;
        unsigned int b37 : 1;
        unsigned int b38 : 1;
        unsigned int b39 : 1;

        unsigned int b40 : 1;
        unsigned int b41 : 1;
        unsigned int b42 : 1;
        unsigned int b43 : 1;
        unsigned int b44 : 1;
        unsigned int b45 : 1;
        unsigned int b46 : 1;
        unsigned int STP_EM_BRAIN : 1;

        unsigned int b48 : 1;
        unsigned int b49 : 1;
        unsigned int b50 : 1;
        unsigned int b51 : 1;
        unsigned int b52 : 1;
        unsigned int b53 : 1;
        unsigned int b54 : 1;
        unsigned int b55 : 1;
        
        unsigned int b56 : 1;
        unsigned int b57 : 1;
        unsigned int b58 : 1;
        unsigned int b59 : 1;
        unsigned int b60 : 1;
        unsigned int b61 : 1;
        unsigned int b62 : 1;
        unsigned int STP_GAME_UPDATE : 1;
    } &StpFlags = *(Trigger::stpFlags *)(shared::base + 0x17EA070);

    inline struct staFlags
    {
        unsigned int b1 : 1;
        unsigned int b2 : 1;
        unsigned int b3 : 1;
        unsigned int b4 : 1;
        unsigned int b5 : 1;
        unsigned int b6 : 1;
        unsigned int STA_VR : 1;
        unsigned int b8 : 1;

        unsigned int b9 : 1;
        unsigned int STA_BATTLE_BGM : 1;
        unsigned int STA_IN_GAME_EVENT : 1;
        unsigned int STA_CAMERA_IGNORE_COLLIDE : 1;
        unsigned int STA_PAUSE : 1;
        unsigned int b14 : 1;
        unsigned int b15 : 1;
        unsigned int b16 : 1;
        
        unsigned int b17 : 1;
        unsigned int STA_BULLET_WITHOUT_COLLIDE : 1;
        unsigned int STA_CODEC : 1;
        unsigned int STA_PARKOUR_INVALID : 1;
        unsigned int STA_NINJARUN_INVALID : 1;
        unsigned int STA_ALWAYS_ZANGEKI : 1;
        unsigned int STA_NINJARUN : 1;
        unsigned int STA_VR_FIELD : 1;

        unsigned int STA_BLADEADDEFFECT : 1;
        unsigned int STA_QTE : 1;
        unsigned int STA_PLAYER_ATYPE_EFFECT_ON : 1;
        unsigned int STA_SOFT_EVENT : 1;
        unsigned int STA_SUSPEND : 1;
        unsigned int STA_DIE_DEMO : 1;
        unsigned int STA_EVENT : 1;
        unsigned int STA_SCENARIO : 1;

        unsigned int b32 : 1;
        unsigned int b33 : 1;
        unsigned int b34 : 1;
        unsigned int b35 : 1;
        unsigned int b36 : 1;
        unsigned int b37 : 1;
        unsigned int b38 : 1;
        unsigned int b39 : 1;

        unsigned int b40 : 1;
        unsigned int b41 : 1;
        unsigned int b42 : 1;
        unsigned int b43 : 1;
        unsigned int b44 : 1;
        unsigned int b45 : 1;
        unsigned int b46 : 1;
        unsigned int b47 : 1;
        
        unsigned int b48 : 1;
        unsigned int b49 : 1;
        unsigned int b50 : 1;
        unsigned int b51 : 1;
        unsigned int b52 : 1;
        unsigned int b53 : 1;
        unsigned int b54 : 1;
        unsigned int b55 : 1;

        unsigned int STA_COMB_CLEAR : 1;
        unsigned int b57 : 1;
        unsigned int STA_SOFT_EVENT_SKIP_OK : 1;
        unsigned int STA_PAUSE_NO_MOVE : 1;
        unsigned int STA_UI_START_FADE_IN_END : 1;
        unsigned int STA_OBJ_FADE_IN_WAIT : 1;
        unsigned int STA_OBJ_FADE_IN : 1;
        unsigned int b63 : 1;
    } &StaFlags = *(Trigger::staFlags*)(shared::base + 0x17EA060);
};

class Trigger::cCondition
{
public:
    void* m_parameters;
    int field_8;
    int field_C;

    virtual ~cCondition() {};
};

class Trigger::cActionAbstract
{
private:
    virtual void dummyVM() {};
public:

};

class Trigger::cCondPhaseJump : public Trigger::cCondition
{
public:

};

class Trigger::cCondTrue : public Trigger::cCondition
{
public:

};

class Trigger::cTriggerTask
{
public:
    int field_4;
    int field_8;
    int field_C;
    
    virtual ~cTriggerTask() {};
};

struct TriggerManager
{
    struct TriggerRuntime
    {
        int m_nId;
        int field_4;
        int field_8;
        int field_C;
        float field_10;
        float field_14;
        int field_18;
        int field_1C;
        int field_20;
        int field_24;
        int field_28;
        Trigger::cCondition *m_pCondition;
        Trigger::cActionAbstract *m_pAction;
        int field_34;
        float field_38;
    };

    // Hw::cFixedVector field_0;
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;

    Hw::cFixedVector<TriggerRuntime *> m_Triggers;
    Hw::cFixedVector<TriggerRuntime *> m_SoftTriggers;
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
    float field_654;
    int field_658;
    int field_65C;
    float field_660;
    float field_664;
    float field_668;
    float field_66C;
    float field_670;
    int field_674;
    int field_678;
    float field_67C;
    float field_680;
    int field_684;
    int field_688;
    int field_68C;
    lib::StaticArray<Trigger::cTriggerTask*, 16> m_TriggerTasks;
    int field_6E0;
    int field_6E4;
    int field_6E8;
    int field_6EC;
    int field_6F0;
    cFade::Unit *field_6F4;
    int field_6F8;
    float field_6FC;
    int field_700;
};

VALIDATE_SIZE(TriggerManager, 0x704);