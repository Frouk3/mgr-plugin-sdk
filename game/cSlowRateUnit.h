#pragma once

class cSlowRateUnit
{
public:
  int m_nSlowRateType;
  int field_8;
  float m_fSlowRate;
  float m_fRate;
  float m_fDesiredSlowRate;
  float m_fCalculatedSlowRate;
  int field_1C;
  int field_20;
  int field_24;
  int field_28;
  int field_2C;
  int field_30;

  virtual ~cSlowRateUnit() {};
};