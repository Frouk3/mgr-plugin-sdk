#include "shared.h"
#include "cEspControler.h"

void cEspControler::Fade(float duration, float endFade)
{
	CallMethod<shared::base + 0xAAA6E0, cEspControler *, float, float>(this, duration, endFade);
}