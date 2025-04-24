#pragma once

#include <Hw.h>

struct cTaskManager
{
	struct cTask;

	int m_nTaskCapacity;
	cTask* m_pTaskBegin;
	cTask* m_pFirst;
	cTask* m_pLastTask;
	cTask* m_pCurrentTask;
	int m_nTasks;
	cTaskManager* field_18;

	cTaskManager()
	{
		((void(__thiscall*)(cTaskManager*))(shared::base + 0x9D6DF0))(this);
	}

	cTask* reorderTask(unsigned int priority)
	{
		return ((cTask * (__thiscall*)(cTaskManager*, int))(shared::base + 0x9D7420))(this, priority);
	}
	
	int startTask(void(__cdecl *callback)(LPVOID parameter), LPVOID parameter, unsigned int priority, const char* taskName)
	{
		return ((int(__thiscall*)(cTaskManager*, void(__cdecl *)(LPVOID), LPVOID, unsigned int, const char*))(shared::base + 0x9D7870))(this, callback, parameter, priority, taskName);
	}

	void cleanup()
	{
		((void(__thiscall*)(cTaskManager*))(shared::base + 0x9D8450))(this);
	}

	DWORD run(int task)
	{
		return ((int(__thiscall*)(cTaskManager*, int))(shared::base + 0x9D8570))(this, task);
	}

	BOOL startup(unsigned int taskCapacity, unsigned int taskStackSize, Hw::cHeap* allocator)
	{
		return ((BOOL(__thiscall*)(cTaskManager*, unsigned int, unsigned int, Hw::cHeap*))(shared::base + 0x9D8A10))(this, taskCapacity, taskStackSize, allocator);
	}

	void runTasks()
	{
		((void(__thiscall*)(cTaskManager*))(shared::base + 0x9D8DA0))(this);
	}

	~cTaskManager()
	{
		((void(__thiscall*)(cTaskManager*))(shared::base + 0x9D8A00))(this);
	}
};

struct cTaskManager::cTask
{
	cTaskManager* m_pCreator;
	void(__cdecl* m_callback)(LPVOID);
	LPVOID m_callbackparameter;
	int m_nTaskNum;
	int m_nTaskPriority;
	const char* m_TaskName;
	int m_nTaskStatus;
	int m_nTaskId;
	unsigned int m_nTaskStackSize;
	HANDLE m_hSemaphore;
	HANDLE m_hTask;
	cTask* m_pNext;
	cTask* m_pPrev;
	int field_34;

	void cleanup()
	{
		((void(__thiscall*)(cTask*))(shared::base + 0x9D8000))(this);
	}

	DWORD run(int task)
	{
		return ((DWORD(__thiscall*)(cTask*, int))(shared::base + 0x9D80E0))(this, task);
	}
};