#include "cSlowRateManager.h"
#include "shared.h"

cSlowRateManager& g_cSlowRateManager = *(cSlowRateManager*)(shared::base + 0x17E93B0);
cSlowRateManager*& g_pcSlowRateManager = *(cSlowRateManager**)(shared::base + 0x19D9160);

cSlowRateManager* GetcSlowRateManager()
{
	return ((cSlowRateManager *(__cdecl *)())(shared::base + 0xA03960))();
}

void cSlowRateManager::SetSlowRate(eSlowRateType SlowRateType, float SlowRate)
{
	((void(__thiscall*)(cSlowRateManager*, int, float))(shared::base + 0xA03A70))(this, SlowRateType, SlowRate);
}

float cSlowRateManager::GetSlowRate(eSlowRateType SlowRateType)
{
	if (SlowRateType < 4)
		return this->m_fSlowRate[SlowRateType].m_fSlowRate;
	else
		return 1.0f;
}

void cSlowRateManager::ResetSlowRate()
{
	((void(__thiscall*)(cSlowRateManager*))(shared::base + 0xA03B10))(this);
}

void cSlowRateManager::Cleanup()
{
	((void(__thiscall*)(cSlowRateManager*))(shared::base + 0xA08740))(this);
}

cSlowRateUnit *cSlowRateManager::AllocUnit()
{
	return ((cSlowRateUnit *(__thiscall *)(cSlowRateManager *))(shared::base + 0xA06230))(this);
}

cSlowRateManager::cSlowRateManager()
{
	((void (__thiscall *)(cSlowRateManager *))(shared::base + 0xA08FB0))(this);
}

float cSlowRateManager::GetCalculatedRate(eSlowRateType type)
{
	return ((float(__thiscall *)(cSlowRateManager *, int))(shared::base + 0xA03A90))(this, type);
}

void cSlowRateManager::SetSlowRaten(eSlowRateType SlowRateType, float SlowRate)
{
	((void(__cdecl*)(int, float))(shared::base + 0x532020))(SlowRateType, SlowRate);
}

float cSlowRateManager::GetTickRate(eSlowRateType type)
{
	return ((float (__cdecl *)(int))(shared::base + 0x532000))(type);
}

void cSlowRateManager::Reset()
{
	((void(__cdecl*)())(shared::base + 0x11EDC20))();
}