#pragma once
#include <cSlowRateUnit.h>
#include <Hw.h>

class cSlowRate
{
public:
	cSlowRateUnit *m_pUnit;

	cSlowRate() { CallMethod<0xA03940, cSlowRate *>(this); }

	BOOL isValid() { return ReturnCallMethod<BOOL, 0xA03950, cSlowRate*>(this); }
	float get() { return ReturnCallMethod<float, 0xA049B0, cSlowRate*>(this); } // don't even ask about name, it's from the .pdb of Bayonetta

	void cleanup() { CallMethod<0xA060F0, cSlowRate*>(this); }
	~cSlowRate() { CallMethod<0xA085E0, cSlowRate *>(this); }
	// Managed copy constructor with reference count
	cSlowRate& operator=(const cSlowRate& other) { return ReturnCallMethod<cSlowRate&, 0xA08600, cSlowRate *, const cSlowRate&>(this, other); }
	BOOL setSlowType(eSlowRate type) { return ReturnCallMethod<BOOL, 0xA08640, cSlowRate*, eSlowRate>(this, type); }
};

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
	Hw::cHeap* m_pAllocator;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	cSlowRateUnit *m_LastUnit;
	struct SlowRateUnit 
	{
		float m_SlowRate;
		float m_Rate;
		float m_SlowRateBefore;
		float m_Delta;
	} m_aSlowRateUnit[4];
	float m_TickRate;
	float m_Ticks;
	float m_AccumulatedDelta;
	float m_TickDelay;
	float m_TickDifference;
	int m_SampleCount;

	virtual ~cSlowRateManager() {};
	// non virtual destructor at 0xA09010

	cSlowRateManager() { CallMethod<0xA08FB0, cSlowRateManager*>(this); }

	void setTickDelay(float framerate)
	{
		((void(__thiscall*)(cSlowRateManager*, float))(shared::base + 0xA03A50))(this, framerate);
	}

	void setSlowRate(eSlowRate SlowRateType, float SlowRate)
	{
		((void(__thiscall*)(cSlowRateManager*, int, float))(shared::base + 0xA03A70))(this, SlowRateType, SlowRate);
	}

	float getDeltaRate(eSlowRate type)
	{
		return ((float(__thiscall*)(cSlowRateManager*, int))(shared::base + 0xA03A90))(this, type);
	}

	void setRate(eSlowRate slowRateType, float rate)
	{
		((void(__thiscall*)(cSlowRateManager*, int, float))(shared::base + 0xA03AB0))(this, slowRateType, rate);
	}

	float getRate(eSlowRate type)
	{
		return ((float(__thiscall*)(cSlowRateManager*, int))(shared::base + 0xA03AD0))(this, type);
	}

	float getSlowRateBefore(eSlowRate type)
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

	BOOL allocateUnits(size_t units, Hw::cHeap *allocator)
	{
		return ((BOOL(__thiscall*)(cSlowRateManager*, size_t, Hw::cHeap*))(shared::base + 0xA198A0))(this, units, allocator);
	}

	BOOL startup(Hw::cHeap *allocator, float frameRate)
	{
		return ((BOOL(__thiscall*)(cSlowRateManager*, Hw::cHeap*, float))(shared::base + 0xA086A0))(this, allocator, frameRate);
	}

	void cleanup()
	{
		((void(__thiscall*)(cSlowRateManager*))(shared::base + 0xA08740))(this);
	}

	static inline cSlowRateManager* get()
	{
		return ((cSlowRateManager * (__cdecl*)())(shared::base + 0xA03960))();
	}

	// static inline cSlowRateManager& ms_Instance = *(cSlowRateManager*)(shared::base + 0x17E93B0);
	// static inline cSlowRateManager*& ms_pInstance = *(cSlowRateManager**)(shared::base + 0x19D9160); // unconfirmed
};

inline cSlowRateManager &g_RateMan = *(cSlowRateManager*)(shared::base + 0x17E93B0);