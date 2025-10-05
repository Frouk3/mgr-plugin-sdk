#pragma once
#include <cSlowRateUnit.h>
#include <Hw.h>

class cSlowRateManager
{
public:
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	cSlowRateUnit* m_FirstUnit;
	size_t m_nSlowUnitsCapacity;
	Hw::cHeapVariable* m_pAllocator;
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
		float m_fSlowRateBefore;
		float m_fDelta;
	} m_aSlowRateUnit[4];
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

	void setTickDelay(float framerate)
	{
		((void(__thiscall*)(cSlowRateManager*, float))(shared::base + 0xA03A50))(this, framerate);
	}

	void setSlowRate(eSlowRateType SlowRateType, float SlowRate)
	{
		((void(__thiscall*)(cSlowRateManager*, int, float))(shared::base + 0xA03A70))(this, SlowRateType, SlowRate);
	}

	float getDeltaRate(eSlowRateType type)
	{
		return ((float(__thiscall*)(cSlowRateManager*, int))(shared::base + 0xA03A90))(this, type);
	}

	void setRate(eSlowRateType slowRateType, float rate)
	{
		((void(__thiscall*)(cSlowRateManager*, int, float))(shared::base + 0xA03AB0))(this, slowRateType, rate);
	}

	float getRate(eSlowRateType type)
	{
		return ((float(__thiscall*)(cSlowRateManager*, int))(shared::base + 0xA03AD0))(this, type);
	}

	float getSlowRateBefore(eSlowRateType type)
	{
		return ((float(__thiscall*)(cSlowRateManager*, int))(shared::base + 0xA03AF0))(this, type);
	}

	void resetSlowRate()
	{
		((void(__thiscall*)(cSlowRateManager*))(shared::base + 0xA03B10))(this);
	}

	cSlowRateUnit* allocUnit()
	{
		return ((cSlowRateUnit * (__thiscall*)(cSlowRateManager*))(shared::base + 0xA06230))(this);
	}

	BOOL allocateUnits(size_t units, Hw::cHeapVariable *allocator)
	{
		return ((BOOL(__thiscall*)(cSlowRateManager*, size_t, Hw::cHeapVariable*))(shared::base + 0xA198A0))(this, units, allocator);
	}

	BOOL startup(Hw::cHeapVariable *allocator, float frameRate)
	{
		return ((BOOL(__thiscall*)(cSlowRateManager*, Hw::cHeapVariable*, float))(shared::base + 0xA086A0))(this, allocator, frameRate);
	}

	void cleanup()
	{
		((void(__thiscall*)(cSlowRateManager*))(shared::base + 0xA08740))(this);
	}

	static inline cSlowRateManager* get()
	{
		return ((cSlowRateManager * (__cdecl*)())(shared::base + 0xA03960))();
	}

	static inline cSlowRateManager& ms_Instance = *(cSlowRateManager*)(shared::base + 0x17E93B0);
	static inline cSlowRateManager*& ms_pInstance = *(cSlowRateManager**)(shared::base + 0x19D9160);
};