#pragma once
#include "cItemBase.h"

class cItemPossessionBase : public cItemBase
{
public:
  int m_nCount;
  int m_nMaxCount;

  const char *GetParent()
  {
    return ReturnCallVMTFunc<const char*, 4, cItemPossessionBase *>(this);
  }
  int GetMaxCount()
  {
    return ReturnCallVMTFunc<int, 5, cItemPossessionBase *>(this);
  }
  void Receive(int Count)
  {
    CallVMTFunc<6, cItemPossessionBase *, int>(this, Count);
  }
  void Receive()
  {
    CallVMTFunc<7, cItemPossessionBase *>(this);
  }
  void Spend(int Count)
  {
    CallVMTFunc<8, cItemPossessionBase *, int>(this, Count);
  }
  void Spend()
  {
    CallVMTFunc<9, cItemPossessionBase *>(this);
  }
  void Set(int Count)
  {
    CallVMTFunc<10, cItemPossessionBase *, int>(this, Count);
  }
  BOOL IsMaxedOut()
  {
    return ReturnCallVMTFunc<BOOL, 11, cItemPossessionBase *>(this);
  }
  // duplicates at 13 & 14
  BOOL Use()
  {
    return ReturnCallVMTFunc<BOOL, 12, cItemPossessionBase*>(this);
  }

  BOOL IsNotUsable()
  {
    return ReturnCallVMTFunc<BOOL, 17, cItemPossessionBase *>(this);
  }

  void ReceiveNoChange(int Count)
  {
    CallVMTFunc<21, cItemPossessionBase *, int>(this, Count);
  }
};