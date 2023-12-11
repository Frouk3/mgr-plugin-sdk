#pragma once
#include "cCameraViewProj.h"
#include "cVec4.h"
#include <D3dx9math.h>
#include "EntityHandle.h"

class Pl0000;

class cCamera : public cCameraViewProj
{
public:
  int field_4;
  int field_8;
  int field_C;
  D3DXMATRIX field_10;
  D3DXMATRIX field_50;
  float field_90;
  float m_fFOV;
  float m_fNearClip;
  float m_fFarClip;
  int field_A0;
  int field_A4;
  int field_A8;
  int field_AC;
  D3DXMATRIX m_viewMatrix;
  D3DXMATRIX field_F0;
  D3DXMATRIX field_130;
  D3DXMATRIX field_170;
  float field_1B0[2][4];
  float field_1D0[3];
  cCamera *field_1DC;
  float field_1E0[4];
  int field_1F0;
  float field_1F4;
  float field_1F8;
  float field_1FC;
  D3DXMATRIX field_200;
  D3DXMATRIX field_240;
  D3DXMATRIX field_280;
  void *field_2C0;
  char pad_2C4[12];
  D3DXMATRIX field_2D0;
  D3DXMATRIX field_310;
  int field_350;
  int field_354;
  int field_358;
  int field_35C;
  cVec4 field_360;
  EntityHandle m_nPlayerHandle;
  Pl0000 *m_pPlayer[2];
  char pad_37C[20];
  D3DXMATRIX field_390;
  D3DXMATRIX field_3D0;

  virtual ~cCamera() override {}
};

VALIDATE_SIZE(cCamera, 0x410);