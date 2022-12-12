#pragma once

enum GameMenuStatus
{
  InMenu = 0x0,
  InGame = 0x1,
  ProcessPause = 0x2,
  PauseMenu = 0x3,
  Codec = 0x4,
  StateDisallowPause = 0x5,
  CutscenePause = 0x6,
  VRFail = 0x7,
  MissionFail = 0x8,
  SelectWeaponMenu = 0x9,
  GraphicsSettings = 0xA,
  AttackHelpScreen = 0xB,
  Pause1 = 0xC,
  MainMenuLoad = 0xD,
  LoadingIntoBossMission = 0xE,
  VRMissionListLoading = 0xF,
  NONE = 0x10,
  LoadingIntoMission = 0x11,
  ProcessOutOfPause = 0x12,
};

