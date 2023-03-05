#include "Behavior.h"
#include "shared.h"

void Behavior::Startup()
{
    ((void(__thiscall *)(Behavior *))(shared::base + 0x691E90))(this);
}

Behavior::Behavior()
{
    ((void(__thiscall *)(Behavior *))(shared::base + 0x6A3540))(this);
}