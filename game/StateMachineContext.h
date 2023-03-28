#pragma once

#include "StateMachineFactory.h"

class StateMachineContext
{
public:
  StateMachineFactory *m_pStateMachineFactory;
  float field_8;

  virtual ~StateMachineContext() {};
};