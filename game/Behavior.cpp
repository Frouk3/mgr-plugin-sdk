#include "Behavior.h"
#include "shared.h"

void Behavior::Startup() noexcept
{
    DWORD address = shared::base + 0x691E90;
    ((void(__thiscall *)(Behavior *))address)(this);
}

Behavior::Behavior() noexcept
{
    DWORD address = shared::base + 0x6A3540;
    ((void(__thiscall *)(Behavior *))address)(this);
}

Behavior::~Behavior() noexcept
{
    DWORD address = shared::base + 0x6A3690;
    ((void(__thiscall *)(Behavior *))address)(this);
}