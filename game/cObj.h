#pragma once

#include "cXmlBinary.h"
#include "cModel.h"
#include "Entity.h"

class cObj : public cModel
{
public:
  int field_490;
  int m_nAnimationHandle;
  int field_498;
  int field_49C;
  int m_nSetType;
  int m_nType;
  int m_nSetFlag;
  int m_nSetRtn;
  unsigned int m_nModelIndex;
  unsigned int m_nClothIndex;
  int field_4B8;
  int m_nAnimIndex;
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
  Entity *m_pEntity;
  cXmlBinary field_4F4;
  int field_514;
  int field_518;
  int field_51C;
  int field_520;
  int field_524;
  int field_528;
  int field_52C;

  // vft

  void *GetContext();
  bool CreateDummy();
  void Function3();
  void Function4(); // nullsub

  void Function5();
  void Function6();
  void EnableRender();
  void DisableRender();
  float Function9(); // return 1.0
  void Function10(int a2);
  void Function11(); // nullsub

  void Function12();
  void Function13();
  int GetRenderable();
  void UpdateCollision(int a2);
  // vft end 

  cObj();
};

VALIDATE_SIZE(cObj, 0x530);