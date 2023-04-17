#include "CharacterControl.h"
#include "shared.h"

bool CharacterControl::IsOnGround()
{
    return ((bool (__thiscall *)(CharacterControl *))(shared::base + 0x4E2740))(this);
}