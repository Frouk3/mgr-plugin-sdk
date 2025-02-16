#pragma once

#include <StateMachineFactory.h>

class StateMachineContext
{
public:
  StateMachineFactory *m_Factory;
  float field_8;

  virtual ~StateMachineContext() {};
};