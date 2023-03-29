#pragma once
#include "shared.h"

namespace Trigger
{
    class cCondition;

    extern struct gameFlags {
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
    } &GameFlags;

    extern struct stpFlags
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
        unsigned int b11 : 1;
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
    } &StpFlags;

    extern struct staFlags
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
    } &StaFlags;
};

class Trigger::cCondition
{
public:
    int field_4;
    int field_8;
    int field_C;

    virtual ~cCondition() {};
    bool CanRun();
};