#pragma once

#include "cXmlBinary.h"
#include "cModel.h"
#include "EntityHandle.h"

class cObj : public cModel
{
public:
  int field_490;
  int field_494;
  int field_498;
  int field_49C;
  int field_4A0;
  int field_4A4;
  unsigned int field_4A8;
  int field_4AC;
  unsigned int field_4B0;
  int field_4B4;
  int field_4B8;
  int field_4BC;
  int field_4C0;
  int field_4C4;
  char field_4C8;
  char field_4C9;
  int field_4CC;
  int field_4D0;
  int field_4D4;
  int field_4D8;
  int field_4DC;
  int field_4E0;
  int field_4E4;
  int field_4E8;
  int field_4EC;
  EntityHandle *m_pEntityHandle;
  cXmlBinary field_4F4;
  int field_514;
  int field_518;
  int field_51C;
  int field_520;
  int field_524;
  int field_528;
  int field_52C;

  cObj() noexcept;
  ~cObj() noexcept;
  void EnableRender() noexcept;
  void DisableRender() noexcept;
};