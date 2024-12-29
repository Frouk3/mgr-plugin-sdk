#pragma once

#include <Hw.h>

struct cJobManager
{
	struct JobTask
	{
		cJobManager* m_pOwner;
		int m_nThreadIndex;
		HANDLE m_hSemaphore;
		HANDLE field_C;
		void(__cdecl *m_pFunc)(LPVOID reserved, void *arg);
		void* m_pFuncParameter;
	};

	JobTask* m_pJobs;
	int m_nJobCapacity;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	int field_70;
	int field_74;
	int field_78;
	int field_7C;
	int field_80;
	int field_84;
	int field_88;
	int field_8C;
	int field_90;
	int field_94;
	int field_98;
	int field_9C;
	int field_A0;
	int field_A4;
	int field_A8;
	int field_AC;
	int field_B0;

	cJobManager()
	{
		((void(__thiscall*)(cJobManager*))(shared::base + 0x9D6F30))(this);
	}

	~cJobManager()
	{
		((void(__thiscall*)(cJobManager*))(shared::base + 0x9D8B60))(this);
	}

	int shutdown()
	{
		return ((int(__thiscall*)(cJobManager*))(shared::base + 0x9D8860))(this);
	}

	unsigned int getCurrentThreadId()
	{
		return ((unsigned int(__thiscall*)(cJobManager*))(shared::base + 0x9D7AD0))(this);
	}

	void scheduleJob(void(__cdecl* function)(LPVOID reserved, LPVOID parameter), LPVOID parameter, unsigned int jobIndex)
	{
		((void(__thiscall*)(cJobManager*, void(__cdecl*)(LPVOID, LPVOID), LPVOID, unsigned int))(shared::base + 0x9D75D0))(this, function, parameter, jobIndex);
	}

	BOOL startup(size_t jobAmount, int* threadIndices, Hw::cHeap* allocator, void* a5, void* a6, const char** threadNames, int a8)
	{
		return ((BOOL(__thiscall*)(cJobManager*, size_t, int*, Hw::cHeap*, void*, void*, const char**, int))(shared::base + 0x9D8B70))(this, jobAmount, threadIndices, allocator, a5, a6, threadNames, a8);
	}

	void setJobConcurrency(unsigned int jobs)
	{
		((void(__thiscall*)(cJobManager*, unsigned int))(shared::base + 0x9D79A0))(this, jobs);
	}
};