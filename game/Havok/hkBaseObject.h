#pragma once

#include <shared.h>
#include <hkBaseTypes.h>

class hkBaseObject
{
public:

  virtual ~hkBaseObject() {};
  virtual void __first_virtual_table_function__() {};
};

VALIDATE_SIZE(hkBaseObject, 0x4);