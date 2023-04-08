#pragma once
#include <Windows.h>

namespace Hw
{
    class cHeap;
    class cHeapVariableBase;
    class cHeapVariable;
    class cTexture;
    class CameraProj;
    class cCameraBase;
    class cHeapPhysical;
    class cHeapHook;
    class cHeapFixed;
    class cHeapOneTime;
    class cHeapPhysicalBase;
    class cHeapGlobal;
    class cShareHeapPhysical;
    class cPrimHeap;
    class cIndexBufferHeap;
}

class Hw::cHeap
{
public:
  int field_4;
  int field_8;
  int field_C;
  int field_10;
  int field_14;
  int field_18;
  int field_1C;
  int field_20;
  int field_24;
  int field_28;
  Hw::cHeapGlobal *m_pGlobalHeap;
  Hw::cHeapVariable *m_pNext;
  Hw::cHeapVariable *m_pPrev;
  char *m_TargetAlloc;
  int field_3C;
  HANDLE *m_pHandle;
  int field_44;
  int field_48;
  int m_nMaxPhysical;
  int m_nFreePhysical;
  int field_54;
  int field_58;
  int field_5C;

  virtual ~cHeap() {};
};

class Hw::cHeapVariableBase : public Hw::cHeap
{
public:

  virtual ~cHeapVariableBase() override {};
};

class Hw::cHeapVariable : public Hw::cHeapVariableBase
{
public:

  virtual ~cHeapVariable() override {};
  void *AllocateMemory(size_t size, Hw::cHeapVariable *heap);
};

class Hw::cTexture
{
public:
  int field_4;
  int field_8;
  int field_C;
  int field_10;
  int field_14;
  int field_18;

  virtual ~cTexture() {};
};

class Hw::CameraProj
{
public:

  virtual ~CameraProj() {};
};

class Hw::cCameraBase
{
public:

  virtual ~cCameraBase() {};
};

class Hw::cHeapPhysicalBase : public Hw::cHeap
{
public:
  int field_60;
  int field_64;
  int field_68;
  int field_6C;

  virtual ~cHeapPhysicalBase() override {};
};

class Hw::cHeapPhysical : public Hw::cHeapPhysicalBase
{
public:

  virtual ~cHeapPhysical() override {};
};

class Hw::cHeapHook
{
public:

  virtual ~cHeapHook() {};
};

class Hw::cHeapFixed : public Hw::cHeap
{
public:

  virtual ~cHeapFixed() override {};
};

class Hw::cHeapOneTime : public Hw::cHeap
{
public:

  virtual ~cHeapOneTime() override {};
};

class Hw::cHeapGlobal : public Hw::cHeapVariableBase
{
public:

  virtual ~cHeapGlobal() override {};
};

class Hw::cShareHeapPhysical : Hw::cHeapPhysical
{
public:

  virtual ~cShareHeapPhysical() override {};
};

class Hw::cPrimHeap
{
public:
  int field_4;
  int field_8;
  int field_C;
  int field_10;

  virtual ~cPrimHeap() {};
};

class Hw::cIndexBufferHeap
{
public:
  int field_4;
  int field_8;
  int field_C;
  int field_10;
  int field_14;
  int field_18;
  
  virtual ~cIndexBufferHeap() {};
};