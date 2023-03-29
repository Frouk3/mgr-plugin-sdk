#include "Trigger.h"
#include "shared.h"

bool Trigger::cCondition::CanRun()
{
    return ((bool (__thiscall *)(Trigger::cCondition *))(shared::base + 0x877C40))(this);
}

Trigger::staFlags &Trigger::StaFlags = *(Trigger::staFlags*)(shared::base + 0x17EA060);
Trigger::stpFlags &Trigger::StpFlags = *(Trigger::stpFlags *)(shared::base + 0x17EA070);
Trigger::gameFlags &Trigger::GameFlags = *(Trigger::gameFlags*)(shared::base + 0x17EA090);