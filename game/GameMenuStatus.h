#pragma once
#include "../shared/shared.h"

// shared::base + 0x17E9F9C
enum GameMenuStatus
{
  InMenu = 0,
  InGame = 1,
  ProcessPause = 2,
  PauseMenu = 3,
  Codec = 4,
  StateDisallowPause = 5,
  CutscenePause = 6,
  VRFail = 7,
  MissionFail = 8,
  SelectWeaponMenu = 9,
  GraphicsSettings = 10,
  AttackHelpScreen = 11,
  Pause1 = 12,
  MainMenuLoad = 13,
  LoadingIntoBossMission = 14,
  VRMissionListLoading = 15,
  NONE = 16,
  LoadingIntoMission = 17,
  ProcessOutOfPause = 18,
};

unsigned int &g_GameMenuStatus = *(unsigned int*)(shared::base + 0x17E9F9C);