#include "Trigger.h"
#include "shared.h"

bool Trigger::cCondition::CanRun()
{
    return ((bool (__thiscall *)(Trigger::cCondition *))(shared::base + 0x877C40))(this);
}