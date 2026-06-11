#pragma once

#include <FileRead.h>

class cGame
{
public:
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int m_nCoreDatReader;
    int m_nCoreDttReader;
    int m_TempDataBuffer;
    int field_30;
    int m_nCoreEffDataId;
    int m_nCoreEffDttId;
    int field_3C;
    int field_40;
    int m_nCoreUIDataId;
    int m_nCoreUIDttId;
    int field_4C;
    int field_50;
    int m_nCoreDlcDataId;
    int field_58;
    int field_5C;
    int field_60;
    Hw::cTaskManager m_TaskManager;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int m_bShowInterface;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
};

inline struct staFlags
{
    union
    {
        struct
        {        
            unsigned int b1 : 1;                         // 0x00000001 (index = 0)
            unsigned int b2 : 1;                         // 0x00000002 (index = 1)
            unsigned int b3 : 1;                         // 0x00000004 (index = 2)
            unsigned int b4 : 1;                         // 0x00000008 (index = 3)
            unsigned int b5 : 1;                         // 0x00000010 (index = 4)
            unsigned int b6 : 1;                         // 0x00000020 (index = 5)
            unsigned int STA_VR : 1;                     // 0x00000040 (index = 6)
            unsigned int b8 : 1;                         // 0x00000080 (index = 7)

            unsigned int b9 : 1;                         // 0x00000100 (index = 8)
            unsigned int STA_BATTLE_BGM : 1;             // 0x00000200 (index = 9)
            unsigned int STA_IN_GAME_EVENT : 1;          // 0x00000400 (index = 10)
            unsigned int STA_CAMERA_IGNORE_COLLIDE : 1;  // 0x00000800 (index = 11)
            unsigned int STA_PAUSE : 1;                  // 0x00001000 (index = 12)
            unsigned int b14 : 1;                        // 0x00002000 (index = 13)
            unsigned int STA_REQUEST_HOOK_LOADING : 1;   // 0x00004000 (index = 14)
            unsigned int STA_DRAW_END : 1;               // 0x00008000 (index = 15)

            unsigned int b17 : 1;                        // 0x00010000 (index = 16)
            unsigned int STA_BULLET_WITHOUT_COLLIDE : 1; // 0x00020000 (index = 17)
            unsigned int STA_CODEC : 1;                  // 0x00040000 (index = 18)
            unsigned int STA_PARKOUR_INVALID : 1;        // 0x00080000 (index = 19)
            unsigned int STA_NINJARUN_INVALID : 1;       // 0x00100000 (index = 20)
            unsigned int STA_ALWAYS_ZANGEKI : 1;         // 0x00200000 (index = 21)
            unsigned int STA_NINJARUN : 1;               // 0x00400000 (index = 22)
            unsigned int STA_VR_FIELD : 1;               // 0x00800000 (index = 23)

            unsigned int STA_BLADEADDEFFECT : 1;         // 0x01000000 (index = 24)
            unsigned int STA_QTE : 1;                    // 0x02000000 (index = 25)
            unsigned int STA_PLAYER_ATYPE_EFFECT_ON : 1; // 0x04000000 (index = 26)
            unsigned int STA_SOFT_EVENT : 1;             // 0x08000000 (index = 27)
            unsigned int STA_SUSPEND : 1;                // 0x10000000 (index = 28)
            unsigned int STA_DIE_DEMO : 1;               // 0x20000000 (index = 29)
            unsigned int STA_EVENT : 1;                  // 0x40000000 (index = 30)
            unsigned int STA_SCENARIO : 1;               // 0x80000000 (index = 31)

            unsigned int b32 : 1;                        // 0x00000001 (index = 0)
            unsigned int b33 : 1;                        // 0x00000002 (index = 1)
            unsigned int b34 : 1;                        // 0x00000004 (index = 2)
            unsigned int b35 : 1;                        // 0x00000008 (index = 3)
            unsigned int b36 : 1;                        // 0x00000010 (index = 4)
            unsigned int b37 : 1;                        // 0x00000020 (index = 5)
            unsigned int b38 : 1;                        // 0x00000040 (index = 6)
            unsigned int b39 : 1;                        // 0x00000080 (index = 7)

            unsigned int b40 : 1;                        // 0x00000100 (index = 8)
            unsigned int b41 : 1;                        // 0x00000200 (index = 9)
            unsigned int b42 : 1;                        // 0x00000400 (index = 10)
            unsigned int b43 : 1;                        // 0x00000800 (index = 11)
            unsigned int b44 : 1;                        // 0x00001000 (index = 12)
            unsigned int b45 : 1;                        // 0x00002000 (index = 13)
            unsigned int STA_EVENT_FRAME_MODE : 1;       // 0x00004000 (index = 14)
            unsigned int b47 : 1;                        // 0x00008000 (index = 15)

            unsigned int b48 : 1;                        // 0x00010000 (index = 16)
            unsigned int b49 : 1;                        // 0x00020000 (index = 17)
            unsigned int b50 : 1;                        // 0x00040000 (index = 18)
            unsigned int b51 : 1;                        // 0x00080000 (index = 19)
            unsigned int b52 : 1;                        // 0x00100000 (index = 20)
            unsigned int b53 : 1;                        // 0x00200000 (index = 21)
            unsigned int b54 : 1;                        // 0x00400000 (index = 22)
            unsigned int b55 : 1;                        // 0x00800000 (index = 23)

            unsigned int STA_COMB_CLEAR : 1;             // 0x01000000 (index = 24)
            unsigned int b57 : 1;                        // 0x02000000 (index = 25)
            unsigned int STA_SOFT_EVENT_SKIP_OK : 1;     // 0x04000000 (index = 26)
            unsigned int STA_PAUSE_NO_MOVE : 1;          // 0x08000000 (index = 27)
            unsigned int STA_UI_START_FADE_IN_END : 1;   // 0x10000000 (index = 28)
            unsigned int STA_OBJ_FADE_IN_WAIT : 1;       // 0x20000000 (index = 29)
            unsigned int STA_OBJ_FADE_IN : 1;            // 0x40000000 (index = 30)
            unsigned int b63 : 1;                        // 0x80000000 (index = 31)
        };
        unsigned int m_flags[4];
    };
} &g_StaFlags = *(staFlags*)(shared::base + 0x17EA060);

inline struct gameFlags 
{
    union 
    {
        struct
        {
            unsigned int GAME_QTE_UI_DISABLE : 1;               // 0x00000001 (index = 0)
            unsigned int GAME_MUGEN_ZANGEKI : 1;                // 0x00000002 (index = 1)
            unsigned int GAME_OS_BOOT_MODE : 1;                 // 0x00000004 (index = 2)
            unsigned int GAME_PLAYER_ONESHOT_OFF : 1;           // 0x00000008 (index = 3)
            unsigned int GAME_PLAYER_ONEHAND : 1;               // 0x00000010 (index = 4)
            unsigned int GAME_RIPPERMODE_OFF : 1;               // 0x00000020 (index = 5)
            unsigned int GAME_NAVI_UI_ON : 1;                   // 0x00000040 (index = 6)
            unsigned int GAME_PLAYER_NO_OVERHEAT : 1;           // 0x00000080 (index = 7)

            unsigned int GAME_PLAYER_NO_DIE : 1;                // 0x00000100 (index = 8)
            unsigned int GAME_SYSTEM_MAPAUTOLOAD_OFF : 1;       // 0x00000200 (index = 9)
            unsigned int GAME_PLAYER_JUMP_OFF : 1;              // 0x00000400 (index = 10)
            unsigned int GAME_PLAYER_DATSU_OFF : 1;             // 0x00000800 (index = 11)
            unsigned int GAME_PLAYER_GECKO_TRAIL : 1;           // 0x00001000 (index = 12)
            unsigned int GAME_PLAYER_GUARD_OFF : 1;             // 0x00002000 (index = 13)
            unsigned int GAME_PLAYER_NINJYARUN_OFF : 1;         // 0x00004000 (index = 14)
            unsigned int GAME_PLAYER_ZANGEKI_OFF : 1;           // 0x00008000 (index = 15)

            unsigned int GAME_ACTIVE_B_PUSH : 1;                // 0x00010000 (index = 16)
            unsigned int GAME_ACTIVE_Y_POUND : 1;               // 0x00020000 (index = 17)
            unsigned int GAME_L1_ATTACK_OFF : 1;                // 0x00040000 (index = 18)
            unsigned int GAME_IGNORE_PARKOUR_SLIDING : 1;       // 0x00080000 (index = 19)
            unsigned int GAME_IGNORE_PARKOUR_WALL : 1;          // 0x00100000 (index = 20)
            unsigned int GAME_IGNORE_PARKOUR_DOWNWARDCLIFF : 1; // 0x00200000 (index = 21)
            unsigned int GAME_IGNORE_PARKOUR_LOWOVER : 1;       // 0x00400000 (index = 22)
            unsigned int GAME_PLAYER_ATTACK_OFF : 1;            // 0x00800000 (index = 23)

            unsigned int GAME_PLAYER_WALK_ONLY : 1;             // 0x01000000 (index = 24)
            unsigned int GAME_MISSILE_NINJYARUN_MODE : 1;       // 0x02000000 (index = 25)
            unsigned int GAME_PLAYERBATTLEMOTIONEND_DEMO : 1;   // 0x04000000 (index = 26)
            unsigned int GAME_PLAYERBATTLEEND_DEMO : 1;         // 0x08000000 (index = 27)
            unsigned int GAME_AUTO_HPUP : 1;                    // 0x10000000 (index = 28)
            unsigned int GAME_ZANGEKIMODE : 1;                  // 0x20000000 (index = 29)
            unsigned int GAME_RECVCOMMU : 1;                    // 0x40000000 (index = 30)
            unsigned int GAME_PROLOGUE : 1;                     // 0x80000000 (index = 31)

            unsigned int GAME_TGS_MODE : 1;                     // 0x00000001 (index = 0)
            unsigned int GAME_XY_ATTACK_OFF : 1;                // 0x00000002 (index = 1)
            unsigned int GAME_TUTORIAL_FROM_STORY : 1;          // 0x00000004 (index = 2)
            unsigned int b35 : 1;                               // 0x00000008 (index = 3)
            unsigned int b36 : 1;                               // 0x00000010 (index = 4)
            unsigned int GAME_DISABLE_ZANGEKI : 1;              // 0x00000020 (index = 5)
            unsigned int GAME_PLAYER_VISOR_ENABLED : 1;         // 0x00000040 (index = 6)
            unsigned int GAME_RUNNING_X_ATTACK_OFF : 1;         // 0x00000080 (index = 7)

            unsigned int b40 : 1;                               // 0x00000100 (index = 8)
            unsigned int b41 : 1;                               // 0x00000200 (index = 9)
            unsigned int GAME_PLAYER_NO_LOCKON_BUTTON : 1;      // 0x00000400 (index = 10)
            unsigned int b43 : 1;                               // 0x00000800 (index = 11)
            unsigned int GAME_EM0091_MANUPILATE : 1;            // 0x00001000 (index = 12)
            unsigned int b45 : 1;                               // 0x00002000 (index = 13)
            unsigned int GAME_HP1_RAIDEN : 1;                   // 0x00004000 (index = 14)
            unsigned int GAME_DEPRESSSION_RAIDEN : 1;           // 0x00008000 (index = 15)

            unsigned int GAME_SOLDIER_MONOLOGUE : 1;            // 0x00010000 (index = 16)
            unsigned int GAME_KOGEKKO_PLAY : 1;                 // 0x00020000 (index = 17)
            unsigned int GAME_WEAPON_SELECT : 1;                // 0x00040000 (index = 18)
            unsigned int GAME_SLIDER_NINJARUN_MODE : 1;         // 0x00080000 (index = 19)
            unsigned int GAME_CODEC_SUBJECTIVE_POINT_VIEW : 1;  // 0x00100000 (index = 20)
            unsigned int GAME_INZANGEKI_CAMDIR : 1;             // 0x00200000 (index = 21)
            unsigned int GAME_CAMERA_INVERSE_X : 1;             // 0x00400000 (index = 22)
            unsigned int GAME_CAMERA_INVERSE_Y : 1;             // 0x00800000 (index = 23)

            unsigned int GAME_NO_EXP_ADD : 1;                   // 0x01000000 (index = 24)
            unsigned int GAME_ITEM_NO_DROP : 1;                 // 0x02000000 (index = 25)
            unsigned int GAME_PHASE_END_UI_DISP_OFF : 1;        // 0x04000000 (index = 26)
            unsigned int GAME_RESULT_DISP_ON : 1;               // 0x08000000 (index = 27)
            unsigned int GAME_BATTLECOLLISION_OFF : 1;          // 0x10000000 (index = 28)
            unsigned int GAME_PLAYER_NO_DIVEKILL : 1;           // 0x20000000 (index = 29)
            unsigned int GAME_PLAYER_NO_MOVE : 1;               // 0x40000000 (index = 30)
            unsigned int GAME_PLAYER_NO_XA : 1;                 // 0x80000000 (index = 31)
        };
        unsigned int m_flags[4];
	};
} &g_GameFlags = *(gameFlags*)(shared::base + 0x17EA090);

inline struct stpFlags
{
    union
    {
        struct
        {
            unsigned int b1 : 1;              // 0x00000001 (index = 0)
            unsigned int b2 : 1;              // 0x00000002 (index = 1)
            unsigned int b3 : 1;              // 0x00000004 (index = 2)
            unsigned int b4 : 1;              // 0x00000008 (index = 3)
            unsigned int b5 : 1;              // 0x00000010 (index = 4)
            unsigned int b6 : 1;              // 0x00000020 (index = 5)
            unsigned int b7 : 1;              // 0x00000040 (index = 6)
            unsigned int STP_KEY_INPUT : 1;   // 0x00000080 (index = 7)

            unsigned int b9 : 1;              // 0x00000100 (index = 8)
            unsigned int b10 : 1;             // 0x00000200 (index = 9)
            unsigned int STP_MOUSE_UPDATE : 1;// 0x00000400 (index = 10)
            unsigned int STP_TRG_DELAY_PL_CHK : 1; // 0x00000800 (index = 11)
            unsigned int STP_SITUATION : 1;   // 0x00001000 (index = 12)
            unsigned int STP_ENEMYSET : 1;    // 0x00002000 (index = 13)
            unsigned int STP_SCENARIO : 1;    // 0x00004000 (index = 14)
            unsigned int STP_EVENT_SKIP : 1;  // 0x00008000 (index = 15)

            unsigned int STP_TRIGGER : 1;     // 0x00010000 (index = 16)
            unsigned int STP_PL_CAM_KEY : 1;  // 0x00020000 (index = 17)
            unsigned int STP_IK : 1;          // 0x00040000 (index = 18)
            unsigned int STP_PL_ATTACK_KEY : 1; // 0x00080000 (index = 19)
            unsigned int STP_PL_MOVE_KEY : 1; // 0x00100000 (index = 20)
            unsigned int STP_PL_KEY : 1;      // 0x00200000 (index = 21)
            unsigned int STP_SUBPL : 1;       // 0x00400000 (index = 22)
            unsigned int STP_SHADOW : 1;      // 0x00800000 (index = 23)

            unsigned int STP_FILTER : 1;      // 0x01000000 (index = 24)
            unsigned int STP_UI : 1;          // 0x02000000 (index = 25)
            unsigned int STP_SCR : 1;         // 0x04000000 (index = 26)
            unsigned int STP_ESP : 1;         // 0x08000000 (index = 27)
            unsigned int STP_ETCOBJ : 1;      // 0x10000000 (index = 28)
            unsigned int STP_EM : 1;          // 0x20000000 (index = 29)
            unsigned int STP_PL : 1;          // 0x40000000 (index = 30)
            unsigned int STP_OBJ : 1;         // 0x80000000 (index = 31)

            unsigned int b32 : 1;             // 0x00000001 (index = 0)
            unsigned int b33 : 1;             // 0x00000002 (index = 1)
            unsigned int b34 : 1;             // 0x00000004 (index = 2)
            unsigned int b35 : 1;             // 0x00000008 (index = 3)
            unsigned int b36 : 1;             // 0x00000010 (index = 4)
            unsigned int b37 : 1;             // 0x00000020 (index = 5)
            unsigned int b38 : 1;             // 0x00000040 (index = 6)
            unsigned int b39 : 1;             // 0x00000080 (index = 7)

            unsigned int b40 : 1;             // 0x00000100 (index = 8)
            unsigned int b41 : 1;             // 0x00000200 (index = 9)
            unsigned int b42 : 1;             // 0x00000400 (index = 10)
            unsigned int b43 : 1;             // 0x00000800 (index = 11)
            unsigned int b44 : 1;             // 0x00001000 (index = 12)
            unsigned int b45 : 1;             // 0x00002000 (index = 13)
            unsigned int b46 : 1;             // 0x00004000 (index = 14)
            unsigned int STP_EM_BRAIN : 1;    // 0x00008000 (index = 15)

            unsigned int b48 : 1;             // 0x00010000 (index = 16)
            unsigned int b49 : 1;             // 0x00020000 (index = 17)
            unsigned int b50 : 1;             // 0x00040000 (index = 18)
            unsigned int b51 : 1;             // 0x00080000 (index = 19)
            unsigned int b52 : 1;             // 0x00100000 (index = 20)
            unsigned int b53 : 1;             // 0x00200000 (index = 21)
            unsigned int b54 : 1;             // 0x00400000 (index = 22)
            unsigned int b55 : 1;             // 0x00800000 (index = 23)
            
            unsigned int b56 : 1;             // 0x01000000 (index = 24)
            unsigned int b57 : 1;             // 0x02000000 (index = 25)
            unsigned int b58 : 1;             // 0x04000000 (index = 26)
        	unsigned int b59 : 1;             // 0x08000000 (index = 27)
            unsigned int b60 : 1;             // 0x10000000 (index = 28)
            unsigned int b61 : 1;             // 0x20000000 (index = 29)
            unsigned int b62 : 1;             // 0x40000000 (index = 30)
            unsigned int STP_GAME_UPDATE : 1; // 0x80000000 (index = 31)
	    };
    	unsigned int m_flags[4];
    };
} &g_StpFlags = *(stpFlags*)(shared::base + 0x17EA070);

enum GAME_FLAG : unsigned __int32
{
    GAME_PROLOGUE=0,
    GAME_RECVCOMMU=1, 
    GAME_ZANGEKIMODE=2, 
    GAME_AUTO_HPUP=3, 
    GAME_PLAYERBATTLEEND_DEMO=4, 
    GAME_PLAYERBATTLEMOTIONEND_DEMO=5, 
    GAME_MISSILE_NINJYARUN_MODE=6, 
    GAME_PLAYER_WALK_ONLY=7, 
    GAME_PLAYER_ATTACK_OFF=8, 
    GAME_IGNORE_PARKOUR_LOWOVER=9, 
    GAME_IGNORE_PARKOUR_DOWNWARDCLIFF=10, 
    GAME_IGNORE_PARKOUR_WALL=11, 
    GAME_IGNORE_PARKOUR_SLIDING=12, 
    GAME_L1_ATTACK_OFF=13, 
    GAME_ACTIVE_Y_POUND=14, 
    GAME_ACTIVE_B_PUSH=15, 
    GAME_PLAYER_ZANGEKI_OFF=16, 
    GAME_PLAYER_NINJYARUN_OFF=17, 
    GAME_PLAYER_GUARD_OFF=18, 
    GAME_PLAYER_GECKO_TRAIL=19, 
    GAME_PLAYER_DATSU_OFF=20, 
    GAME_PLAYER_JUMP_OFF=21, 
    GAME_SYSTEM_MAPAUTOLOAD_OFF=22, 
    GAME_PLAYER_NO_DIE=23, 
    GAME_PLAYER_NO_OVERHEAT=24, 
    GAME_NAVI_UI_ON=25, 
    GAME_RIPPERMODE_OFF=26, 
    GAME_PLAYER_ONEHAND=27, 
    GAME_PLAYER_ONESHOT_OFF=28, 
    GAME_OS_BOOT_MODE=29, 
    GAME_MUGEN_ZANGEKI=30, 
    GAME_QTE_UI_DISABLE=31, 
    GAME_PLAYER_NO_XA=32, 
    GAME_PLAYER_NO_MOVE=33, 
    GAME_PLAYER_NO_DIVEKILL=34, 
    GAME_BATTLECOLLISION_OFF=35, 
    GAME_RESULT_DISP_ON=36, 
    GAME_PHASE_END_UI_DISP_OFF=37, 
    GAME_ITEM_NO_DROP=38, 
    GAME_NO_EXP_ADD=39, 
    GAME_INZANGEKI_CAMDIR=42, 
    GAME_CODEC_SUBJECTIVE_POINT_VIEW=43, 
    GAME_SLIDER_NINJARUN_MODE=44, 
    GAME_WEAPON_SELECT=45, 
    GAME_KOGEKKO_PLAY=46, 
    GAME_SOLDIER_MONOLOGUE=47, 
    GAME_DEPRESSSION_RAIDEN=48, 
    GAME_HP1_RAIDEN=49, 
    GAME_EM0091_MANUPILATE=51, 
    GAME_TUTORIAL_FROM_STORY=61, 
    GAME_XY_ATTACK_OFF=62, 
    GAME_TGS_MODE=63, 
    GAME_SHOOTING_FINISH=97, 
    GAME_GEKKO_JAMMING_ESCAPE_MOMENT_CAMERA=98, 
    GAME_PLAYER_NO_LOCKON_BUTTON=53
};

enum STA_FLAG : unsigned __int32
{
    STA_SCENARIO=0, 
    STA_EVENT=1, 
    STA_DIE_DEMO=2, 
    STA_SUSPEND=3, 
    STA_SOFT_EVENT=4, 
    STA_PLAYER_ATYPE_EFFECT_ON=5, 
    STA_QTE=6, 
    STA_BLADEADDEFFECT=7, 
    STA_VR_FIELD=8, 
    STA_NINJARUN=9, 
    STA_ALWAYS_ZANGEKI=10, 
    STA_NINJARUN_INVALID=11, 
    STA_PARKOUR_INVALID=12, 
    STA_CODEC=13, 
    STA_BULLET_WITHOUT_COLLIDE=14, 
    STA_PAUSE=19, 
    STA_CAMERA_IGNORE_COLLIDE=20, 
    STA_IN_GAME_EVENT=21, 
    STA_BATTLE_BGM=22, 
    STA_OBJ_FADE_IN=33, 
    STA_OBJ_FADE_IN_WAIT=34, 
    STA_UI_START_FADE_IN_END=35, 
    STA_PAUSE_NO_MOVE=36, 
    STA_SOFT_EVENT_SKIP_OK=37, 
    STA_COMB_CLEAR=39
};

enum STP_FLAG : unsigned __int32
{
    STP_OBJ=0, 
    STP_PL=1, 
    STP_EM=2, 
    STP_ETCOBJ=3, 
    STP_ESP=4, 
    STP_SCR=5, 
    STP_UI=6, 
    STP_FILTER=7, 
    STP_SHADOW=8, 
    STP_SUBPL=9, 
    STP_PL_KEY=10, 
    STP_PL_MOVE_KEY=11, 
    STP_PL_ATTACK_KEY=12, 
    STP_IK=13, 
    STP_PL_CAM_KEY=14, 
    STP_TRIGGER=15, 
    STP_EVENT_SKIP=16, 
    STP_SCENARIO=17, 
    STP_ENEMYSET=18, 
    STP_TRG_DELAY_PL_CHK=20, 
    STP_GAME_UPDATE=32, 
    STP_EM_BRAIN=48 
};

inline BOOL __cdecl ckStaFlag(STA_FLAG flag) { return MAKE_CALL(shared::base + 0x16910, BOOL(__cdecl *)(STA_FLAG), flag); }
inline void __cdecl onStaFlag(STA_FLAG flag) { MAKE_CALL(shared::base + 0x168D0, void(__cdecl *)(STA_FLAG), flag); }
inline void __cdecl offStaFlag(STA_FLAG flag) { MAKE_CALL(shared::base + 0x168F0, void(__cdecl *)(STA_FLAG), flag); }

inline BOOL __cdecl ckStpFlag(STP_FLAG flag) { return MAKE_CALL(shared::base + 0x3FF60, BOOL(__cdecl *)(STP_FLAG), flag); }
inline void __cdecl onStpFlag(STP_FLAG flag) { MAKE_CALL(shared::base + 0x9CCE0, void(__cdecl *)(STP_FLAG), flag); }
inline void __cdecl offStpFlag(STP_FLAG flag) { MAKE_CALL(shared::base + 0x9CD00, void(__cdecl *)(STP_FLAG), flag); }

inline BOOL __cdecl ckGameFlag(GAME_FLAG flag) { return MAKE_CALL(shared::base + 0x16D50, BOOL(__cdecl *)(GAME_FLAG), flag); }
inline void __cdecl onGameFlag(GAME_FLAG flag) { MAKE_CALL(shared::base + 0x9CC70, void(__cdecl *)(GAME_FLAG), flag); }
inline void __cdecl offGameFlag(GAME_FLAG flag) { MAKE_CALL(shared::base + 0x9CC90, void(__cdecl *)(GAME_FLAG), flag); }