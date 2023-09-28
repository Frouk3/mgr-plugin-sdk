#pragma once

#include "hkBaseObject.h"

class hkReferencedObject : public hkBaseObject
{
public:
  int field_4;

  virtual void* getClassType() {};
};