#pragma once
#include "cVec4.h"
#include "shared.h"

class cParts
{
public:
  int field_4;
  int field_8;
  int field_C;
  float field_10;
  float field_14;
  float field_18;
  float field_1C;
  float field_20;
  float field_24;
  float field_28;
  float field_2C;
  float field_30;
  float field_34;
  float field_38;
  float field_3C;
  cVec4 m_vecPos;
  cVec4 m_vecOffset;
  float field_60;
  float field_64;
  float field_68;
  float field_6C;
  cVec4 m_vecSize;
  float field_80;
  float field_84;
  float field_88;
  int field_8C;
  cVec4 m_vecRotation;
  short m_nPartIndex;
  struct {
    unsigned short b01 : 1;
    unsigned short bFreezeModelRotation : 1;
    unsigned short bFreezePosition : 1;
    unsigned short bFreezeSize : 1;
    unsigned short b05 : 1;
    unsigned short b06 : 1;
    unsigned short b07 : 1;
    unsigned short b08 : 1;

    unsigned short b09 : 1;
    unsigned short b10 : 1;
    unsigned short b11 : 1;
    unsigned short b12 : 1;
    unsigned short b13 : 1;
    unsigned short b14 : 1;
    unsigned short bFreezeRotation : 1; // same as bFreezeModelRotation
    unsigned short b16 : 1;
  } m_nPartsFlag;
  int field_A4;
  int field_A8;
  int field_AC;

  virtual ~cParts() {};
};

VALIDATE_SIZE(cParts, 0xB0);