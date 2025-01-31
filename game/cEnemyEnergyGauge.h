#pragma once

#include <cUISystem.h>

class cEnemyEnergyGauge
{
public:
    int field_4;

    virtual ~cEnemyEnergyGauge() {};
};

class cEnemyEnergyGaugeBase : public cCustomObjWorkBase{};
class cEnemyEnergyGaugePrologueBase : public cCustomObjWorkBase{};