#pragma once

#include "cCustomObjCtrlManager.h"

class cCustomObjCtrlManagerEx : public cCustomObjCtrlManager
{
public:
  float field_1C;
  float field_20;
  float field_24;
  int field_28;
  int field_2C;
  float field_30;
  float field_34;
  float field_38;
  float field_3C;
  float field_40;
  float field_44;
  float field_48;
  float field_4C;
  float field_50;
  float field_54;
  float field_58;
  float field_5C;
  float field_60;
  float field_64;
  float field_68;
  float field_6C;
  float field_70;
  float field_74;
  float field_78;
  float field_7C;
  float field_80;
  float field_84;
  float field_88;
  float field_8C;

  virtual ~cCustomObjCtrlManagerEx() override {};
  virtual void Function1() override = 0;
  virtual void Function2() override = 0;
  virtual void Function3() override = 0;
  virtual void Function4() override = 0;
  virtual void Function5() override = 0;
  virtual void Function6() override = 0;
};