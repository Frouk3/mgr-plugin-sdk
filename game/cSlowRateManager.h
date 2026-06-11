#pragma once
#include <cSlowRateUnit.h>
#include <Hw.h>

class cSlowRate
{
public:
	cSlowRateUnit *m_pUnit;

	cSlowRate() { MAKE_CALL(shared::base + 0xA03940, void(__thiscall *)(cSlowRate*), this); }

	BOOL isValid() { return MAKE_CALL(shared::base + 0xA03950, BOOL(__thiscall *)(cSlowRate*), this); }
	float get() { return MAKE_CALL(shared::base + 0xA049B0, float(__thiscall *)(cSlowRate*), this); } // don't even ask about name, it's from the .pdb of Bayonetta

	void cleanup() { MAKE_CALL(shared::base + 0xA060F0, void(__thiscall *)(cSlowRate*), this); }
	~cSlowRate() { MAKE_CALL(shared::base + 0xA085E0, void(__thiscall *)(cSlowRate*), this); }
	// Managed copy constructor with reference count
	cSlowRate& operator=(const cSlowRate& other) { return MAKE_CALL(shared::base + 0xA08600, cSlowRate&(__thiscall *)(cSlowRate*, const cSlowRate&), this, other); }
	BOOL setSlowType(eSlowRate type) { return MAKE_CALL(shared::base + 0xA08640, BOOL(__thiscall *)(cSlowRate*, eSlowRate), this, type); }
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

	cSlowRateManager() { MAKE_CALL(shared::base + 0xA08FB0, void(__thiscall *)(cSlowRateManager*), this); }

	void setTickDelay(float framerate)
	{
		MAKE_CALL(shared::base + 0xA03A50, void(__thiscall *)(cSlowRateManager*, float), this, framerate);
	}

	void setSlowRate(eSlowRate SlowRateType, float SlowRate)
	{
		MAKE_CALL(shared::base + 0xA03A70, void(__thiscall *)(cSlowRateManager*, int, float), this, SlowRateType, SlowRate);
	}

	float getDeltaRate(eSlowRate type)
	{
		return MAKE_CALL(shared::base + 0xA03A90, float(__thiscall *)(cSlowRateManager*, int), this, type);
	}

	void setRate(eSlowRate slowRateType, float rate)
	{
		MAKE_CALL(shared::base + 0xA03AB0, void(__thiscall *)(cSlowRateManager*, int, float), this, slowRateType, rate);
	}

	float getRate(eSlowRate type)
	{
		return MAKE_CALL(shared::base + 0xA03AD0, float(__thiscall *)(cSlowRateManager*, int), this, type);
	}

	float getSlowRateBefore(eSlowRate type)
	{
		return MAKE_CALL(shared::base + 0xA03AF0, float(__thiscall *)(cSlowRateManager*, int), this, type);
	}

	void resetSlowRate()
	{
		MAKE_CALL(shared::base + 0xA03B10, void(__thiscall *)(cSlowRateManager*), this);
	}

	cSlowRateUnit* allocUnit()
	{
		return MAKE_CALL(shared::base + 0xA06230, cSlowRateUnit*(__thiscall *)(cSlowRateManager*), this);
	}

	BOOL allocateUnits(size_t units, Hw::cHeap *allocator)
	{
		return MAKE_CALL(shared::base + 0xA198A0, BOOL(__thiscall *)(cSlowRateManager*, size_t, Hw::cHeap*), this, units, allocator);
	}

	BOOL startup(Hw::cHeap *allocator, float frameRate)
	{
		return MAKE_CALL(shared::base + 0xA086A0, BOOL(__thiscall *)(cSlowRateManager*, Hw::cHeap*, float), this, allocator, frameRate);
	}

	void cleanup()
	{
		MAKE_CALL(shared::base + 0xA08740, void(__thiscall *)(cSlowRateManager*), this);
	}

	static inline cSlowRateManager* get()
	{
		return MAKE_CALL(shared::base + 0xA03960, cSlowRateManager * (__cdecl*)());
	}

	// static inline cSlowRateManager& ms_Instance = *(cSlowRateManager*)(shared::base + 0x17E93B0);
	// static inline cSlowRateManager*& ms_pInstance = *(cSlowRateManager**)(shared::base + 0x19D9160); // unconfirmed
};

inline cSlowRateManager &g_RateMan = *(cSlowRateManager*)(shared::base + 0x17E93B0);