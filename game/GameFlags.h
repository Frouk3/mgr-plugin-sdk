#pragma once
#include "shared.h"

// shared::base + 0x17EA090
// Can be long???
static struct GameFlags {
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
} &g_GameFlags = *(GameFlags *)(shared::base + 0x17EA090);