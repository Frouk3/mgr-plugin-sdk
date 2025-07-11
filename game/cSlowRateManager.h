#pragma once
#include "cSlowRateUnit.h"
#include "Hw.h"

class cSlowRateManager
{
public:
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	cSlowRateUnit* m_FirstUnit;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	cSlowRateUnit *m_LastUnit;
	struct SlowRateUnit 
	{
		float m_fSlowRate;
		float m_fRate;
		float m_fDesiredRate;
		float m_fCalculatedSlowRate;
	} m_SlowRateUnit[4];
	float m_fTickRate;
	float m_fTicks;
	float field_84;
	float m_fTickDelay;
	float m_fTickDifference;
	int field_90;

	virtual ~cSlowRateManager() {};
	
	cSlowRateManager()
	{
		((void(__thiscall*)(cSlowRateManager*))(shared::base + 0xA08FB0))(this);
	}

	void SetSlowRate(eSlowRateType SlowRateType, float SlowRate)
	{
		((void(__thiscall*)(cSlowRateManager*, int, float))(shared::base + 0xA03A70))(this, SlowRateType, SlowRate);
	}

	float getSlowRate(eSlowRateType SlowRateType)
	{
		if (SlowRateType > SLOWRATE_ETC)
			return 1.0f;

		return m_SlowRateUnit[static_cast<int>(SlowRateType)].m_fSlowRate;
	}

	void ResetSlowRate()
	{
		((void(__thiscall*)(cSlowRateManager*))(shared::base + 0xA03B10))(this);
	}

	void Cleanup()
	{
		((void(__thiscall*)(cSlowRateManager*))(shared::base + 0xA08740))(this);
	}

	float GetCalculatedRate(eSlowRateType type)
	{
		return ((float(__thiscall*)(cSlowRateManager*, int))(shared::base + 0xA03A90))(this, type);
	}

	cSlowRateUnit* AllocUnit()
	{
		return ((cSlowRateUnit * (__thiscall*)(cSlowRateManager*))(shared::base + 0xA06230))(this);
	}

	static inline void SetSlowRaten(eSlowRateType SlowRateType, float SlowRate)
	{
		((void(__cdecl*)(int, float))(shared::base + 0x532020))(SlowRateType, SlowRate);
	}

	static inline float GetTickRate(eSlowRateType type)
	{
		return ((float(__cdecl*)(int))(shared::base + 0x532000))(type);
	}

	static inline cSlowRateManager* Get()
	{
		return ((cSlowRateManager * (__cdecl*)())(shared::base + 0xA03960))();
	}

	static inline cSlowRateManager& Instance = *(cSlowRateManager*)(shared::base + 0x17E93B0);
	static inline cSlowRateManager*& pInstance = *(cSlowRateManager**)(shared::base + 0x19D9160);
};