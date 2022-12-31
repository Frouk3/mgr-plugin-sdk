#include "shared.h"
#include "cEspControler.h"

unsigned int cEspControler::SetEffectDuration(float duration, float a3) noexcept
{
	DWORD address = shared::base + 0xAAA6E0;
	return ((unsigned int(__thiscall*)(cEspControler*, float, float))address)(this, duration, a3);
}