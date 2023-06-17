#include "shared.h"
#include "cEspControler.h"

void cEspControler::Fade(float duration, float endFade)
{
	((void (__thiscall *)(cEspControler *, float, float))(shared::base + 0xAAA6E0))(this, duration, endFade);
}