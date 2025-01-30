#pragma once

#include <Hw.h>

struct cTaskManager
{
	struct cTask;

	int m_TaskCapacity;
	cTask* m_TaskBegin;
	cTask* m_First;
	cTask* m_LastTask;
	cTask* m_CurrentTask;
	int m_Tasks;
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
	cTaskManager* m_Creator;
	void(__cdecl* m_callback)(LPVOID);
	LPVOID m_callbackparameter;
	int m_nTaskNum;
	int m_nTaskPriority;
	const char* m_TaskName;
	int m_TaskStatus;
	int m_TaskId;
	unsigned int m_TaskStackSize;
	HANDLE m_hSemaphore;
	HANDLE m_hTask;
	cTask* m_Next;
	cTask* m_Prev;
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