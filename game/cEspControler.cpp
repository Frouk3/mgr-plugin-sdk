#include "shared.h"
#include "cEspControler.h"

unsigned int cEspControler::SetEffectDuration(float duration, float a3)
{
	return ((unsigned int(__thiscall*)(cEspControler*, float, float))(shared::base + 0xAAA6E0))(this, duration, a3);
}